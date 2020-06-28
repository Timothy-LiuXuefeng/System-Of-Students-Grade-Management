#include "subject.h"

basic_info::scoreType Subject::GetAverage() const
{
	scoreType sum = 0; 
	if (studentList.size() == 0) return 0; //û��ѧ�������ſ�
	for (std::map<basic_info::idType, basic_info::scoreType>::const_iterator itr = studentList.begin();
		itr != studentList.end(); ++itr)
	{
		sum += itr->second; 
	}
	return sum / studentList.size(); 
}

bool Subject::InsertStudent(basic_info::idType studentId, basic_info::scoreType score)
{
	if (studentList.find(studentId) != studentList.end()) return false;		//�Ѿ������ѧ����
	studentList.insert(std::make_pair(studentId, score)); 
	return true; 
}

bool Subject::ChangeScore(basic_info::idType studentId, basic_info::scoreType score)
{
	if (studentList.find(studentId) == studentList.end()) return false;		//û�����ѧ��
	studentList[studentId] = score; 
	return true; 
}

basic_info::scoreType Subject::GetScore(basic_info::idType studentId) const
{
	if (studentList.find(studentId) == studentList.end()) return -1;		//û�����ѧ��
	return studentList.at(studentId); 
}

bool Subject::DeleteStudent(basic_info::idType studentId)
{
	if (studentList.find(studentId) == studentList.end()) return false;		//û�����ѧ��
	studentList.erase(studentId); 
	return true; 
}

