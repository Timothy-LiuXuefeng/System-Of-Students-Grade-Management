
#ifndef INFO_H

#define INFO_H

///////////////////////////////////////////////
///////////////////�����Ϣ/////////////////////
///////////////////////////////////////////////

#include <map>
#include "basic.h"

class Student; 
class Subject; 
class Class; 

class Info																//���ȫ����Ϣ
{
public: 
	const std::map<basic_info::idType, Student*>& GetStudentList() const { return studentList; }
	const std::map<basic_info::idType, Subject*>& GetSubjectList() const { return subjectList; }
	const std::map<basic_info::idType, Class*>& GetClassList() const { return classList; }

	friend class ChangeInfo; 
private: 
	std::map<basic_info::idType, Student*> studentList;			//����ѧ���б�
	std::map<basic_info::idType, Subject*> subjectList;			//����ѧ���б�
	std::map<basic_info::idType, Class*> classList;				//���а༶�б�
}; 

extern Info info; 

enum modeType					//ģʽ
{
	compulsory,					//���޿�ģʽ
	optional					//ѡ��ģʽ
}; 

extern modeType mode; 

#endif	//#ifndef INFO_H
