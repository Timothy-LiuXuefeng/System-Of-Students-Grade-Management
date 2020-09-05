#include "info.h"

void Info::Clear()
{
	for (std::map<basic_info::idType, Student*>::const_iterator itr = studentList.begin();
		itr != studentList.end(); ++itr) delete itr->second;
	studentList.clear();

	for (std::map<basic_info::idType, Subject*>::const_iterator itr = subjectList.begin();
		itr != subjectList.end(); ++itr) delete itr->second;
	subjectList.clear();

	for (std::map<basic_info::idType, Class*>::const_iterator itr = classList.begin();
		itr != classList.end(); ++itr) delete itr->second;
	classList.clear();
}


basic_info::scoreType Info::GetClassAverage(basic_info::idType classID) const
{
	std::map<basic_info::idType, Class*>::const_iterator itr = classList.find(classID);
	if (itr == classList.end()) return 0;									//û������༶
	Class* pClass = itr->second; 
	if (pClass->GetStudentList().empty()) return 0;							//����û��ѧ��
	basic_info::scoreType sum = 0; 
	for (std::set<basic_info::idType>::const_iterator itr = pClass->GetStudentList().begin();
		itr != pClass->GetStudentList().end(); ++itr)
		sum += GetStudentValid(*itr); 
	return sum / pClass->GetStudentList().size(); 
}

basic_info::scoreType Info::GetSubjectAverage(basic_info::idType subjectID) const
{
	std::map<basic_info::idType, Subject*>::const_iterator itr = subjectList.find(subjectID); 
	if (itr == subjectList.end()) return 0;									//û�����ſγ�
	Subject* pSubject = itr->second; 
	basic_info::scoreType sum = 0; 
	if (pSubject->GetStudentList().size() == 0) return 0; //û��ѧ�������ſ�
	for (std::map<basic_info::idType, basic_info::scoreType>::const_iterator itr = pSubject->GetStudentList().begin();
		itr != pSubject->GetStudentList().end(); ++itr)
	{
		sum += itr->second; 
	}
	return sum / pSubject->GetStudentList().size();
}

basic_info::scoreType Info::GetStudentAverage(basic_info::idType studentID) const
{
	std::map<basic_info::idType, Student*>::const_iterator itr = studentList.find(studentID);
	if (itr == studentList.end()) return 0;									//û�����ѧ��
	Student* pStudent = itr->second; 
	if (pStudent->GetSubjectList().empty()) return 0;						//ûѧ���κο�
	basic_info::scoreType sum = 0; 
	int sumCredit = 0; 
	for (std::map<basic_info::idType, basic_info::scoreType>::const_iterator itr = pStudent->GetSubjectList().begin();
		itr != pStudent->GetSubjectList().end(); ++itr)
	{
		sum += itr->second * subjectList.at(itr->first)->GetCredit(); 
		sumCredit += subjectList.at(itr->first)->GetCredit(); 
	}
	return sumCredit ? sum / sumCredit : 0; 
}

basic_info::scoreType Info::GetStudentSum(basic_info::idType studentID) const
{
	std::map<basic_info::idType, Student*>::const_iterator itr = studentList.find(studentID);
	if (itr == studentList.end()) return 0;									//û�����ѧ��
	Student* pStudent = itr->second;
	basic_info::scoreType sum = 0;
	for (std::map<basic_info::idType, basic_info::scoreType>::const_iterator itr = pStudent->GetSubjectList().begin();
		itr != pStudent->GetSubjectList().end(); ++itr)
		sum += itr->second; 
	return sum; 
}

int Info::GetStudentCredit(basic_info::idType studentID) const
{
	std::map<basic_info::idType, Student*>::const_iterator itr = studentList.find(studentID);
	if (itr == studentList.end()) return 0;									//û�����ѧ��
	Student* pStudent = itr->second;
	if (pStudent->GetSubjectList().empty()) return 0;						//ûѧ���κο�
	int sumCredit = 0;
	for (std::map<basic_info::idType, basic_info::scoreType>::const_iterator itr = pStudent->GetSubjectList().begin();
		itr != pStudent->GetSubjectList().end(); ++itr)
	{
		sumCredit += subjectList.at(itr->first)->GetCredit();
	}
	return sumCredit; 
}


bool Info::InsertSubject(basic_info::idType id, const std::string& name, basic_info::scoreType fullScore, int credit)
{
	if (subjectList.find(id) != subjectList.end()) return false;			//�Ѿ������ID��
	Subject* tmp = new Subject(id, name, fullScore, credit);
	subjectList.insert(std::make_pair(id, tmp));
	return true;
}

Info::operr Info::ChangeSubjectID(basic_info::idType srcID, basic_info::idType newID)
{
	if (subjectList.find(srcID) == subjectList.end()) return operr::no_subject;
	if (subjectList.find(newID) != subjectList.end()) return operr::subject_exist;

	//���Ŀγ��б�
	Subject* tmp = subjectList.at(srcID);
	subjectList.erase(srcID);
	tmp->SetID(newID);
	subjectList.insert(std::make_pair(newID, tmp));

	//����ѧϰ�Ŀγ̵�ѧ���б�
	for (std::map<basic_info::idType, basic_info::scoreType>::const_iterator itr = tmp->GetStudentList().begin();
		itr != tmp->GetStudentList().end(); ++itr)
	{
		Student* stu = studentList.at(itr->first);
		stu->DeleteSubject(srcID);
		stu->InsertSubject(newID, itr->second);
	}
	return Info::operr::success;
}

bool Info::DeleteSubject(basic_info::idType id)
{
	if (subjectList.find(id) == subjectList.end()) return false;				//�����ڸÿγ�
	Subject* sub = subjectList.at(id);											//��ȡ�ÿγ�ָ��
	for (std::map<basic_info::idType, basic_info::scoreType>::const_iterator itr = sub->GetStudentList().begin();
		itr != sub->GetStudentList().end(); ++itr)
	{
		studentList.at(itr->first)->DeleteSubject(id);							//ɾ��ѧ����ϰ�Ŀ�Ŀ
	}
	subjectList.erase(id);														//���б���ɾ���ÿ�Ŀ
	delete sub;																	//�ͷ��ڴ�ռ�
	return true;
}

bool Info::InsertClass(basic_info::idType id, const std::string& name)
{
	if (classList.find(id) != classList.end()) return false;			//�Ѿ������ID��
	Class* tmp = new Class(id, name);
	classList.insert(std::make_pair(id, tmp));
	return true;
}

Info::operr Info::ChangeClassID(basic_info::idType srcID, basic_info::idType newID)
{
	if (classList.find(srcID) == classList.end()) return operr::no_class;
	if (classList.find(newID) != classList.end()) return operr::class_exist;

	//���İ༶�б�
	Class* tmp = classList.at(srcID);
	classList.erase(srcID);
	tmp->SetID(newID);
	classList.insert(std::make_pair(newID, tmp));

	//�����ڸð༶��ѧ���б�
	for (std::set<basic_info::idType>::const_iterator itr = tmp->GetStudentList().begin();
		itr != tmp->GetStudentList().end(); ++itr)
	{
		Student* stu = studentList.at(*itr);
		stu->SetClassID(newID);
	}
	return Info::operr::success;
}

Info::operr Info::DeleteClass(basic_info::idType id)
{
	if (classList.find(id) == classList.end()) return Info::operr::no_class;				//����������༶
	Class* cls = classList.at(id);															//���ָ��
	if (!(cls->GetStudentList().empty())) return Info::operr::student_exist;				//�༶����ѧ��
	classList.erase(id);																	//���б������
	delete cls;																				//�ͷ��ڴ�
	return Info::operr::success;
}

bool Info::InsertStudent(basic_info::idType id, const std::string& name, Student::genderType gender, basic_info::idType classID)
{
	if (studentList.find(id) != studentList.end()
		|| classList.find(classID) == classList.end())
		return false;															//�Ѿ�����ͬID��ѧ����û�и�ID�İ༶
	Student* tmp = new Student(id, name, gender, classID);
	studentList.insert(std::make_pair(id, tmp));
	classList.at(classID)->InsertStudent(id);
	return true;
}

bool Info::DeleteStudent(basic_info::idType id)
{
	if (studentList.find(id) == studentList.end()) return false;				//û������ѧ��
	Student* stu = studentList.at(id);											//��ȡѧ��ָ��

	//ɾ������ϰ�����пγ̼�¼
	for (std::map<basic_info::idType, basic_info::scoreType>::const_iterator itr = stu->GetSubjectList().begin();
		itr != stu->GetSubjectList().end(); ++itr)
	{
		subjectList.at(itr->first)->DeleteStudent(id);
	}

	//ɾ���༶�и�ѧ���ļ�¼
	classList.at(stu->GetClassID())->DeleteStudent(id);

	studentList.erase(id);																	//���б���ɾ��ѧ��
	delete stu;																				//�ͷ��ڴ�
	return true;
}

Info::operr Info::AddStudentSubject(basic_info::idType studentID, basic_info::idType subjectID, basic_info::scoreType score)
{
	if (studentList.find(studentID) == studentList.end()) return operr::no_student;			//����������ѧ��
	if (subjectList.find(subjectID) == subjectList.end()) return operr::no_subject;			//���������ſγ�

	//��ѧ���в������ſγ�
	if (!studentList.at(studentID)->InsertSubject(subjectID, score)) return operr::has_studied;		//�Ѿ�ѧ�����ſγ�

	//�ڿγ��м�������ѧ��
	subjectList.at(subjectID)->InsertStudent(studentID, score);
	return operr::success;
}

Info::operr Info::DeleteStudentSubject(basic_info::idType studentID, basic_info::idType subjectID)
{
	if (studentList.find(studentID) == studentList.end()) return Info::operr::no_student;			//û������ѧ��
	Student* stu = studentList.at(studentID);

	//ɾ��ѧ���ĳɼ�
	if (!(stu->DeleteSubject(subjectID))) return Info::operr::no_subject;					//�޸ÿγ̵ĳɼ�

	//ɾ���γ̴��ļ�¼
	subjectList.at(subjectID)->DeleteStudent(studentID);
	return Info::operr::success;
}

Info::operr Info::ChangeStudentClass(basic_info::idType studentID, basic_info::idType newClassID)
{
	if (studentList.find(studentID) == studentList.end()) return operr::no_student;			//����������ѧ��
	if (classList.find(newClassID) == classList.end()) return operr::no_class;				//����������༶
	Student* stu = studentList.at(studentID);												//��ȡѧ��ָ��
	classList.at(stu->GetClassID())->DeleteStudent(studentID);								//ɾ��ԭ�༶
	classList.at(newClassID)->InsertStudent(studentID);										//���°༶������ѧ��
	stu->SetClassID(newClassID);															//�޸�ѧ���İ༶ID
	return Info::operr::success;
}

Info::operr Info::ChangeStudentScore(basic_info::idType studentID, basic_info::idType subjectID, basic_info::scoreType newScore)
{
	if (studentList.find(studentID) == studentList.end()) return operr::no_student;			//����������ѧ��
	Student* stu = studentList.at(studentID);												//��ȡѧ��ָ��

	//������Ϣ
	if (!(stu->ChangeScore(subjectID, newScore)))											//û�����ſγ̵ĳɼ�
		return operr::no_subject;
	subjectList.at(subjectID)->ChangeScore(studentID, newScore);
	return Info::operr::success;
}

Info::operr Info::ChangeStudentID(basic_info::idType srcID, basic_info::idType newID)
{
	if (studentList.find(srcID) == studentList.end()) return operr::no_student;
	if (studentList.find(newID) != studentList.end()) return operr::student_exist;

	//����ѧ���б�
	Student* stu = studentList.at(srcID);
	studentList.erase(srcID);
	stu->SetID(newID);
	studentList.insert(std::make_pair(newID, stu));

	//���İ༶�б�
	Class* cls = classList.at(stu->GetClassID());
	cls->DeleteStudent(srcID);
	cls->InsertStudent(newID);

	//������ѡ�γ�
	for (std::map<basic_info::idType, basic_info::scoreType>::const_iterator itr = stu->GetSubjectList().begin();
		itr != stu->GetSubjectList().end(); ++itr)
	{
		Subject* sub = subjectList.at(itr->first);
		sub->DeleteStudent(srcID);
		sub->InsertStudent(newID, itr->second);
	}
	return operr::success;
}

std::list<basic_info*> Info::ReadFromFile(const std::string& fileName)
{
	std::list<basic_info*> readInfo;
	std::ifstream fin(fileName.c_str(), std::ios::in);
	if (!fin) return readInfo;					//��ʧ�ܣ����ؿ�����
	size_t subNum, clsNum, stuNum;
	std::string name;
	basic_info::idType subID, clsID, stuID;
	basic_info::scoreType fullScore, score;
	int credit, gender;
	int fileMode;
	std::queue<basic_info::idType> subRead;		//����ģʽʹ�ã���¼¼��Ŀ�Ŀ

	//�����ļ�����
	fin >> fileMode;
	if (fileMode != static_cast<int>(mode) || fin.fail())	//���Ͳ�ƥ��
	{
		fin.close(); return readInfo;
	}

	//�����Ŀ����
	fin >> subNum;
	if (fin.fail()) return readInfo;
	while (fin.get() != '\n');								//����
	for (size_t i = 0; i < subNum; ++i)
	{
		std::getline(fin, name);							//�����Ŀ����
		if (mode == modeType::optional)
			fin >> subID >> fullScore >> credit;			//�����ĿID�����ֺ�ѧ��
		else
		{
			fin >> subID >> fullScore;						//�����ĿID������
			credit = 1;
		}
		if (fin.fail())										//�������
		{
			fin.clear();
			readInfo.push_back(NULL);
			continue;
		}
		if (InsertSubject(subID, name, fullScore, credit))	//¼��ɹ�
			readInfo.push_back(subjectList.at(subID));
		else readInfo.push_back(NULL);						//��Ŀ��ͻ��¼��ʧ��
		if (mode == modeType::compulsory) subRead.push(subID);
		while (fin.get() != '\n');							//����
	}

	//����༶��
	fin >> clsNum;
	if (fin.fail()) return readInfo;
	while (fin.get() != '\n');								//����
	for (size_t i = 0; i < clsNum; ++i)
	{
		std::getline(fin, name);							//����༶����
		fin >> clsID;										//����༶ID
		if (fin.fail())										//�������
		{
			fin.clear();
			readInfo.push_back(NULL);
			continue;
		}
		if (InsertClass(clsID, name))						//¼��ɹ�
			readInfo.push_back(classList.at(clsID));
		else readInfo.push_back(NULL);						//¼��ʧ��
		while (fin.get() != '\n');							//����
	}

	readInfo.push_back((basic_info*)-1);					//��ʼ¼��ѧ��

	//¼��ѧ����
	fin >> stuNum;
	if (fin.fail()) return readInfo;
	while (fin.get() != '\n');								//����
	for (size_t i = 0; i < stuNum; ++i)
	{
		std::getline(fin, name);							//����ѧ������
		fin >> stuID >> gender >> clsID;					//����ѧ��ID���Ա�Ͱ༶ID
		if (!fin)											//�������
		{
			fin.clear();
			readInfo.push_back(NULL);
			continue;
		}
		while (fin.get() != '\n');							//����

		//¼��ɹ�
		if (InsertStudent(stuID, name, static_cast<Student::genderType>(gender), clsID))
			readInfo.push_back(studentList.at(stuID));
		else readInfo.push_back(NULL);						//¼��ʧ��

		//����γ�����
		fin >> subNum;
		if (fin.fail())											//����ʧ��
		{
			fin.clear();
			continue;
		}

		if (mode == modeType::optional)
		{

			for (size_t i = 0; i < subNum; ++i)					//¼��γ�
			{
				fin >> subID >> score;
				if (fin.fail())									//�������
				{
					fin.clear();
					readInfo.push_back(NULL);
					continue;
				}
				if (AddStudentSubject(stuID, subID, score) == operr::success)	//¼��ɹ�
					readInfo.push_back(subjectList.at(subID));
				else readInfo.push_back(NULL);									//¼��ʧ��
			}
		}
		else
		{
			size_t j;
			subNum = subRead.size();
			for (j = 0; j < subNum; ++j)
			{
				fin >> score;													//����γ̳ɼ�
				if (fin.fail())													//��ȡʧ��
				{
					fin.clear();
					for (size_t k = j; k < subNum; ++k)
					{
						readInfo.push_back(NULL);
						subID = subRead.front();
						AddStudentSubject(stuID, subID, 0);
						subRead.pop();
						subRead.push(subID);
					}
					break;
				}

				else
				{
					subID = subRead.front();
					if (AddStudentSubject(stuID, subID, score) == operr::success)
						readInfo.push_back(subjectList.at(subID));
					else readInfo.push_back(NULL);
					subRead.pop();
					subRead.push(subID);
				}
			}
			if (j < subNum) continue;
		}
		while (fin.get() != '\n');											//����
	}
	fin.close();
	return readInfo;
}

bool Info::SaveToFile(const std::string& fileName)
{
	std::ofstream fout(fileName.c_str(), std::ios::out);
	if (!fout) return false;

	//��һ�У��洢�ļ�����
	fout << static_cast<int>(mode) << std::endl;

	//д���Ŀ��Ϣ
	//�ڶ��У���Ŀ����n
	fout << subjectList.size() << std::endl;

	//����2n�У�ÿ���д���һ����Ŀ
	for (std::map<basic_info::idType, Subject*>::const_iterator itr = subjectList.begin();
		itr != subjectList.end(); ++itr)
	{
		//ǰһ�д����Ŀ����
		fout << itr->second->GetName() << std::endl;

		//��һ�����δ����Ŀid�����֣�ѧ��ģʽ�����ѧ����
		fout << itr->second->GetID() << ' ' << itr->second->GetFullScore();
		if (mode == modeType::optional) fout << ' ' << itr->second->GetCredit();
		fout << std::endl;
	}


	//��һ�У�����༶��k
	fout << classList.size() << std::endl;

	//����2k�У�ÿ���д���һ���༶
	for (std::map<basic_info::idType, Class*>::const_iterator itr = classList.begin();
		itr != classList.end(); ++itr)
	{
		//ǰһ�д洢�༶����
		fout << itr->second->GetName() << std::endl;

		//��һ�д���༶id
		fout << itr->second->GetID() << std::endl;
	}


	//��һ�У�����ѧ����m
	fout << studentList.size() << std::endl;

	//����3m�У�ÿ3�д���һ��ѧ��
	for (std::map<basic_info::idType, Student*>::const_iterator itr = studentList.begin();
		itr != studentList.end(); ++itr)
	{
		//��һ�У���¼ѧ������
		fout << itr->second->GetName() << std::endl;

		//�ڶ��У����μ�¼ѧ����id���Ա�Ͱ༶id
		fout << itr->second->GetID() << ' ' << static_cast<int>(itr->second->GetGender()) << ' ' << itr->second->GetClassID() << std::endl;

		//�����е�һ�����ּ�¼ѧ���޶��Ŀγ�����
		fout << itr->second->GetSubjectList().size();

		//����ֱ��¼ÿ�ſγ̵�id�ͳɼ�������ģʽ�������id
		for (std::map<basic_info::idType, basic_info::scoreType>::const_iterator itr1 = itr->second->GetSubjectList().begin();
			itr1 != itr->second->GetSubjectList().end(); ++itr1)
		{
			if (mode == modeType::optional) fout << ' ' << itr1->first;
			fout << ' ' << itr1->second;
		}
		fout << std::endl;
	}


	return true;
}

