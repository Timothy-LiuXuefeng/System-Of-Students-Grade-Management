#ifndef CHANGE_INFO_H

#define CHANGE_INFO_H

#include <fstream>
#include <list>
#include "Class.h"

class ChangeInfo					//�ı���Ϣ
{
public:

	enum operr
	{
		success, 
		no_student, 
		no_subject, 
		no_class, 
		has_studied, 
		student_exist, 
		subject_exist, 
		class_exist
	};

	static void Clear();			//�����Ϣ

	//��ѧ�ƵĲ���
	static bool InsertSubject(basic_info::idType id, const std::string& name, basic_info::scoreType fullScore, int credit);
	static bool DeleteSubject(basic_info::idType id);
	static operr ChangeSubjectID(basic_info::idType srcID, basic_info::idType newID);

	//�԰༶�Ĳ���
	static bool InsertClass(basic_info::idType id, const std::string& name);
	static bool DeleteClass(basic_info::idType id);
	static operr ChangeClassID(basic_info::idType srcID, basic_info::idType newID);
	
	//��ѧ���Ĳ���
	static bool InsertStudent(basic_info::idType id, const std::string& name, Student::genderType gender, basic_info::idType classID);
	static bool DeleteStudent(basic_info::idType id);
	static operr AddStudentSubject(basic_info::idType studentID, basic_info::idType subjectID, basic_info::scoreType score); 
	static operr ChangeStudentScore(basic_info::idType studentID, basic_info::idType subjectID, basic_info::scoreType newScore);
	static operr ChangeStudentClass(basic_info::idType studentID, basic_info::idType newClassID); 
	static operr ChangeStudentID(basic_info::idType srcID, basic_info::idType newID); 
	
	//���ڴ浵
	static std::list<basic_info*> ReadFromFile(const std::string& fileName);	//�浵������һ��������¼����Ķ�����Ϣ�����ж������ʧ����ָ��ΪNULL
	static bool SaveToFile(const std::string& fileName);						//����		
};


#endif //#ifndef CHANGE_INFO_H
