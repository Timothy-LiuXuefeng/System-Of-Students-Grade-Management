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
