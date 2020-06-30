
#include "ChangeInfo.h"

void ChangeInfo::Clear()
{
	for (std::map<basic_info::idType, Student*>::const_iterator itr = info.studentList.begin();
		itr != info.studentList.end(); ++itr) delete itr->second;
	info.studentList.clear();

	for (std::map<basic_info::idType, Subject*>::const_iterator itr = info.subjectList.begin();
		itr != info.subjectList.end(); ++itr) delete itr->second;
	info.subjectList.clear();

	for (std::map<basic_info::idType, Class*>::const_iterator itr = info.classList.begin();
		itr != info.classList.end(); ++itr) delete itr->second;
	info.classList.clear();
}

bool ChangeInfo::InsertSubject(basic_info::idType id, const std::string& name, basic_info::scoreType fullScore, int credit)
{
	if (info.subjectList.find(id) != info.subjectList.end()) return false;		//�Ѿ������ID��
	Subject* tmp = new Subject(id, name, fullScore, credit); 
	info.subjectList.insert(std::make_pair(id, tmp)); 
	return true; 
}

ChangeInfo::operr ChangeInfo::ChangeSubjectID(basic_info::idType srcID, basic_info::idType newID)
{
	if (info.GetSubjectList().find(srcID) == info.GetSubjectList().end()) return operr::no_subject; 
	if (info.GetSubjectList().find(newID) != info.GetSubjectList().end()) return operr::subject_exist; 

	//����ѧ���б�
	Subject* tmp = info.GetSubjectList().at(srcID); 
	info.subjectList.erase(srcID); 
	tmp->SetID(newID); 
	info.subjectList.insert(std::make_pair(newID, tmp)); 

	//����ѧϰ��ѧ�Ƶ�ѧ���б�
	for (std::map<basic_info::idType, basic_info::scoreType>::const_iterator itr = tmp->GetStudentList().begin();
		itr != tmp->GetStudentList().end(); ++itr)
	{
		Student* stu = info.GetStudentList().at(itr->first); 
		stu->DeleteSubject(srcID); 
		stu->InsertSubject(newID, itr->second); 
	}
	return ChangeInfo::operr::success; 
}

bool ChangeInfo::DeleteSubject(basic_info::idType id)
{
	if (info.GetSubjectList().find(id) == info.GetSubjectList().end()) return false;		//�����ڸ�ѧ��
	Subject* sub = info.GetSubjectList().at(id);											//��ȡ��ѧ��ָ��
	for (std::map<basic_info::idType, basic_info::scoreType>::const_iterator itr = sub->GetStudentList().begin();
		itr != sub->GetStudentList().end(); ++itr)
	{
		info.GetStudentList().at(itr->first)->DeleteSubject(id);							//ɾ��ѧ����ϰ�Ŀ�Ŀ
	}
	info.subjectList.erase(id);																//���б���ɾ���ÿ�Ŀ
	delete sub;																				//�ͷ��ڴ�ռ�
	return true; 
}

bool ChangeInfo::InsertClass(basic_info::idType id, const std::string& name)
{
	if (info.classList.find(id) != info.classList.end()) return false;			//�Ѿ������ID��
	Class* tmp = new Class(id, name); 
	info.classList.insert(std::make_pair(id, tmp)); 
	return true; 
}

ChangeInfo::operr ChangeInfo::ChangeClassID(basic_info::idType srcID, basic_info::idType newID)
{
	if (info.GetClassList().find(srcID) == info.GetClassList().end()) return operr::no_class;
	if (info.GetClassList().find(newID) != info.GetClassList().end()) return operr::class_exist;

	//���İ༶�б�
	Class* tmp = info.GetClassList().at(srcID);
	info.classList.erase(srcID);
	tmp->SetID(newID);
	info.classList.insert(std::make_pair(newID, tmp));

	//�����ڸð༶��ѧ���б�
	for (std::set<basic_info::idType>::const_iterator itr = tmp->GetStudentList().begin();
		itr != tmp->GetStudentList().end(); ++itr)
	{
		Student* stu = info.GetStudentList().at(*itr);
		stu->SetClassID(newID); 
	}
	return ChangeInfo::operr::success;
}

ChangeInfo::operr ChangeInfo::DeleteClass(basic_info::idType id)
{
	if (info.GetClassList().find(id) == info.GetClassList().end()) return ChangeInfo::operr::no_class;				//����������༶
	Class* cls = info.GetClassList().at(id);																		//���ָ��
	if (!(cls->GetStudentList().empty())) return ChangeInfo::operr::student_exist;									//�༶����ѧ��
	info.classList.erase(id);																						//���б������
	delete cls;																										//�ͷ��ڴ�
	return ChangeInfo::operr::success; 
}

bool ChangeInfo::InsertStudent(basic_info::idType id, const std::string& name, Student::genderType gender, basic_info::idType classID)
{
	if (info.studentList.find(id) != info.studentList.end()
		|| info.classList.find(classID) == info.classList.end())
		return false;															//�Ѿ�����ͬID��ѧ����û�и�ID�İ༶
	Student* tmp = new Student(id, name, gender, classID); 
	info.studentList.insert(std::make_pair(id, tmp)); 
	info.GetClassList().at(classID)->InsertStudent(id); 
	return true; 
}

bool ChangeInfo::DeleteStudent(basic_info::idType id)
{
	if (info.GetStudentList().find(id) == info.GetStudentList().end()) return false;			//û������ѧ��
	Student* stu = info.GetStudentList().at(id);												//��ȡѧ��ָ��
	
	//ɾ������ϰ������ѧ�Ƽ�¼
	for (std::map<basic_info::idType, basic_info::scoreType>::const_iterator itr = stu->GetSubjectList().begin();
		itr != stu->GetSubjectList().end(); ++itr)
	{
		info.GetSubjectList().at(itr->first)->DeleteStudent(id); 
	}

	//ɾ���༶�и�ѧ���ļ�¼
	info.GetClassList().at(stu->GetClassID())->DeleteStudent(id); 

	info.studentList.erase(id);																	//���б���ɾ��ѧ��
	delete stu;																					//�ͷ��ڴ�
	return true; 
}

ChangeInfo::operr ChangeInfo::AddStudentSubject(basic_info::idType studentID, basic_info::idType subjectID, basic_info::scoreType score)
{
	if (info.GetStudentList().find(studentID) == info.GetStudentList().end()) return operr::no_student;			//����������ѧ��
	if (info.GetSubjectList().find(subjectID) == info.GetSubjectList().end()) return operr::no_subject;			//����������ѧ��
	
	//��ѧ���в�������ѧ��
	if (!info.GetStudentList().at(studentID)->InsertSubject(subjectID, score)) return operr::has_studied;		//�Ѿ�ѧ������ѧ��

	//��ѧ���м�������ѧ��
	info.GetSubjectList().at(subjectID)->InsertStudent(studentID, score); 
	return operr::success; 
}

ChangeInfo::operr ChangeInfo::DeleteStudentSubject(basic_info::idType studentID, basic_info::idType subjectID)
{
	if (info.GetStudentList().find(studentID) == info.GetStudentList().end()) return ChangeInfo::operr::no_student;			//û������ѧ��
	Student* stu = info.GetStudentList().at(studentID); 

	//ɾ��ѧ���ĳɼ�
	if (!(stu->DeleteSubject(subjectID))) return ChangeInfo::operr::no_subject;			//�޸�ѧ�Ƶĳɼ�
	
	//ɾ��ѧ�ƴ��ļ�¼
	info.GetSubjectList().at(subjectID)->DeleteStudent(studentID); 
	return ChangeInfo::operr::success; 
}

ChangeInfo::operr ChangeInfo::ChangeStudentClass(basic_info::idType studentID, basic_info::idType newClassID)
{
	if (info.GetStudentList().find(studentID) == info.GetStudentList().end()) return operr::no_student;			//����������ѧ��
	if (info.GetClassList().find(newClassID) == info.GetClassList().end()) return operr::no_class;				//����������༶
	Student* stu = info.GetStudentList().at(studentID);															//��ȡѧ��ָ��
	info.GetClassList().at(stu->GetClassID())->DeleteStudent(studentID);										//ɾ��ԭ�༶
	info.GetClassList().at(newClassID)->InsertStudent(studentID);												//���°༶������ѧ��
	stu->SetClassID(newClassID);																				//�޸�ѧ���İ༶ID
	return ChangeInfo::operr::success; 
}

ChangeInfo::operr ChangeInfo::ChangeStudentScore(basic_info::idType studentID, basic_info::idType subjectID, basic_info::scoreType newScore)
{
	if (info.GetStudentList().find(studentID) == info.GetStudentList().end()) return operr::no_student;			//����������ѧ��
	Student* stu = info.GetStudentList().at(studentID);															//��ȡѧ��ָ��

	//������Ϣ
	if (!(stu->ChangeScore(subjectID, newScore)))																//û������ѧ�Ƶĳɼ�
		return operr::no_subject; 
	info.GetSubjectList().at(subjectID)->ChangeScore(studentID, newScore); 
	return ChangeInfo::operr::success; 
}

ChangeInfo::operr ChangeInfo::ChangeStudentID(basic_info::idType srcID, basic_info::idType newID)
{
	if (info.GetStudentList().find(srcID) == info.GetStudentList().end()) return operr::no_student;
	if (info.GetStudentList().find(newID) != info.GetStudentList().end()) return operr::student_exist; 

	//����ѧ���б�
	Student* stu = info.GetStudentList().at(srcID); 
	info.studentList.erase(srcID); 
	stu->SetID(newID); 
	info.studentList.insert(std::make_pair(newID, stu)); 

	//���İ༶�б�
	Class* cls = info.GetClassList().at(stu->GetClassID()); 
	cls->DeleteStudent(srcID); 
	cls->InsertStudent(newID); 

	//������ѡ�γ�
	for (std::map<basic_info::idType, basic_info::scoreType>::const_iterator itr = stu->GetSubjectList().begin();
		itr != stu->GetSubjectList().end(); ++itr)
	{
		Subject* sub = info.GetSubjectList().at(itr->first); 
		sub->DeleteStudent(srcID); 
		sub->InsertStudent(newID, itr->second); 
	}
	return operr::success; 
}

std::list<basic_info*> ChangeInfo::ReadFromFile(const std::string& fileName)
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
	if (fileMode != static_cast<int>(mode) || fin.fail())		//���Ͳ�ƥ��
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
		if (fin.fail())											//�������
		{
			fin.clear(); 
			readInfo.push_back(NULL); 
			continue; 
		}
		if (InsertSubject(subID, name, fullScore, credit))	//¼��ɹ�
			readInfo.push_back(info.GetSubjectList().at(subID));
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
		if (fin.fail())											//�������
		{
			fin.clear(); 
			readInfo.push_back(NULL); 
			continue; 
		}
		if (InsertClass(clsID, name))						//¼��ɹ�
			readInfo.push_back(info.GetClassList().at(clsID));
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
			readInfo.push_back(info.GetStudentList().at(stuID));
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
				if (fin.fail())										//�������
				{
					fin.clear();
					readInfo.push_back(NULL);
					continue; 
				}
				if (AddStudentSubject(stuID, subID, score) == operr::success)	//¼��ɹ�
					readInfo.push_back(info.GetSubjectList().at(subID));
				else readInfo.push_back(NULL);									//¼��ʧ��
			}
		}
		else
		{
			size_t j; 
			subNum = subRead.size(); 
			for (j = 0; j < subNum; ++j)
			{
				fin >> score;													//����ѧ�Ƴɼ�
				if (fin.fail())														//��ȡʧ��
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
						readInfo.push_back(info.GetSubjectList().at(subID));
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

bool ChangeInfo::SaveToFile(const std::string& fileName)
{
	std::ofstream fout(fileName.c_str(), std::ios::out);
	if (!fout) return false;

	//��һ�У��洢�ļ�����
	fout << static_cast<int>(mode) << std::endl;

	//д���Ŀ��Ϣ
		//�ڶ��У���Ŀ����n
	fout << info.GetSubjectList().size() << std::endl;

	//����2n�У�ÿ���д���һ����Ŀ
	for (std::map<basic_info::idType, Subject*>::const_iterator itr = info.GetSubjectList().begin();
		itr != info.GetSubjectList().end(); ++itr)
	{
		//ǰһ�д����Ŀ����
		fout << itr->second->GetName() << std::endl;

		//��һ�����δ����Ŀid�����֣�ѧ��ģʽ�����ѧ����
		fout << itr->second->GetID() << ' ' << itr->second->GetFullScore(); 
		if (mode == modeType::optional) fout << ' ' << itr->second->GetCredit();
		fout << std::endl;
	}


	//��һ�У�����༶��k
	fout << info.GetClassList().size() << std::endl;

	//����2k�У�ÿ���д���һ���༶
	for (std::map<basic_info::idType, Class*>::const_iterator itr = info.GetClassList().begin();
		itr != info.GetClassList().end(); ++itr)
	{
		//ǰһ�д洢�༶����
		fout << itr->second->GetName() << std::endl;

		//��һ�д���༶id
		fout << itr->second->GetID() << std::endl;
	}


	//��һ�У�����ѧ����m
	fout << info.GetStudentList().size() << std::endl;

	//����3m�У�ÿ3�д���һ��ѧ��
	for (std::map<basic_info::idType, Student*>::const_iterator itr = info.GetStudentList().begin();
		itr != info.GetStudentList().end(); ++itr)
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

