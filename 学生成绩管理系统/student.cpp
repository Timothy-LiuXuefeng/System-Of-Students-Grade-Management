#include "student.h"

bool Student::InsertSubject(basic_info::idType subjectId, basic_info::scoreType score)
{
	if (subjectList.find(subjectId) != subjectList.end()) return false;			//�Ѿ�ѧ�����ſγ�
	subjectList.insert(std::make_pair(subjectId, score)); 
	return true; 
}

bool Student::ChangeScore(basic_info::idType subjectId, basic_info::scoreType score)
{
	if (subjectList.find(subjectId) == subjectList.end()) return false;			//ûѧ�����ſγ�
	subjectList[subjectId] = score; 
	return true; 
}

bool Student::DeleteSubject(basic_info::idType subjectId)
{
	if (subjectList.find(subjectId) == subjectList.end()) return false;			//ûѧ�����ſγ�
	subjectList.erase(subjectId); 
	return true; 
}
