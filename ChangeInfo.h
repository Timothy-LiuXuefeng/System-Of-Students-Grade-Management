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

	static bool InsertSubject(basic_info::idType id, const std::string& name, basic_info::scoreType fullScore, int credit);		//������ѧ��
	static bool DeleteSubject(basic_info::idType id);																			//ɾ��ѧ��
	static operr ChangeSubjectID(basic_info::idType srcID, basic_info::idType newID);											//����ѧ��ID

	//�԰༶�Ĳ���

	static bool InsertClass(basic_info::idType id, const std::string& name);													//�����°༶
	static operr DeleteClass(basic_info::idType id);																			//ɾ���༶
	static operr ChangeClassID(basic_info::idType srcID, basic_info::idType newID);												//�ı�༶ID
	
	//��ѧ���Ĳ���

	static bool InsertStudent(basic_info::idType id, const std::string& name, Student::genderType gender, basic_info::idType classID);	//������ѧ��
	static bool DeleteStudent(basic_info::idType id);																					//ɾ��ѧ��
	static operr AddStudentSubject(basic_info::idType studentID, basic_info::idType subjectID, basic_info::scoreType score);			//Ϊѧ�������ѧ��
	static operr DeleteStudentSubject(basic_info::idType studentID, basic_info::idType subjectID);										//ɾ��ѧ��ѧϰ��ĳѧ�Ƴɼ�
	static operr ChangeStudentScore(basic_info::idType studentID, basic_info::idType subjectID, basic_info::scoreType newScore);		//����ѧ������
	static operr ChangeStudentClass(basic_info::idType studentID, basic_info::idType newClassID);										//����ѧ���༶
	static operr ChangeStudentID(basic_info::idType srcID, basic_info::idType newID);													//����ѧ��ID
	
	//���ڴ浵

	//�浵������һ��������¼����Ķ�����Ϣ�����ж������ʧ����ָ��ΪNULL����ʼ����ѧ��ʱָ��Ϊ-1����0xffffffff
	static std::list<basic_info*> ReadFromFile(const std::string& fileName); 
	//����
	static bool SaveToFile(const std::string& fileName); 
};


#endif //#ifndef CHANGE_INFO_H
