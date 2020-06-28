#include "Class.h"

bool Class::InsertStudent(basic_info::idType studentId)
{
	if (studentList.find(studentId) != studentList.end()) return false;		//�Ѿ������ѧ����
	studentList.insert(studentId); 
	return true; 
}

bool Class::DeleteStudent(basic_info::idType studentId)
{
	if (studentList.find(studentId) == studentList.end()) return false;		//û�����ѧ��
	studentList.erase(studentId);
	return true; 
}

basic_info::scoreType Class::GetAverage() const
{
	if (studentList.empty()) return 0;										//����û��ѧ��
	basic_info::scoreType sum = 0; 
	for (std::set<basic_info::idType>::const_iterator itr = studentList.begin();
		itr != studentList.end(); ++itr)
		sum += info.GetStudentList().at(*itr)->GetValid(); 
	return sum / studentList.size(); 
}
