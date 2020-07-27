
#ifndef INFO_H

#define INFO_H

///////////////////////////////////////////////
//
//  �����Ϣ
//
//

#include <fstream>
#include <map>
#include <list>
#include <queue>
#include "subject.h"
#include "student.h"
#include "Class.h"

class Info																//���ȫ����Ϣ
{
public: 

	enum operr						//��������
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

	enum modeType					//ģʽ
	{
		compulsory,					//���޿�ģʽ
		optional					//ѡ��ģʽ
	};

	//���캯��
	Info() : mode(modeType::optional) {}

	//��ȡ�б�

	const std::map<basic_info::idType, Student*>& GetStudentList() const { return studentList; }
	const std::map<basic_info::idType, Subject*>& GetSubjectList() const { return subjectList; }
	const std::map<basic_info::idType, Class*>& GetClassList() const { return classList; }

	//��ȡ������ģʽ
	modeType GetMode() const { return mode; }
	void SetMode(modeType newMode) { mode = newMode; }

	//�����Ϣ
	void Clear(); 

	//��ȡ����

	//��ȡ�༶����
	basic_info::scoreType GetClassAverage(basic_info::idType classID) const; 

	//��ȡѧ�ƾ���
	basic_info::scoreType GetSubjectAverage(basic_info::idType subjectID) const; 

	//��ȡѧ��ƽ����
	basic_info::scoreType GetStudentAverage(basic_info::idType studentID) const; 
	//��ȡѧ���ܷ�
	basic_info::scoreType GetStudentSum(basic_info::idType studentID) const;
	//������Ч�֣�ѡ��ģʽ��Ϊ����������ģʽ��Ϊ�ܷ�
	basic_info::scoreType GetStudentValid(basic_info::idType studentID) const
	{
		return (mode == modeType::optional) ? GetStudentAverage(studentID) : GetStudentSum(studentID);
	}

	//��ȡѧ���޶���ѧ��
	int GetStudentCredit(basic_info::idType studentID) const;

	//���ֲ���

	//��ѧ�ƵĲ���

	bool InsertSubject(basic_info::idType id, const std::string& name, basic_info::scoreType fullScore, int credit);	//������ѧ��
	bool DeleteSubject(basic_info::idType id);																			//ɾ��ѧ��
	operr ChangeSubjectID(basic_info::idType srcID, basic_info::idType newID);											//����ѧ��ID

	//�԰༶�Ĳ���

	bool InsertClass(basic_info::idType id, const std::string& name);													//�����°༶
	operr DeleteClass(basic_info::idType id);																			//ɾ���༶
	operr ChangeClassID(basic_info::idType srcID, basic_info::idType newID);												//�ı�༶ID

	//��ѧ���Ĳ���

	bool InsertStudent(basic_info::idType id, const std::string& name, Student::genderType gender, basic_info::idType classID);	//������ѧ��
	bool DeleteStudent(basic_info::idType id);																					//ɾ��ѧ��
	operr AddStudentSubject(basic_info::idType studentID, basic_info::idType subjectID, basic_info::scoreType score);			//Ϊѧ�������ѧ��
	operr DeleteStudentSubject(basic_info::idType studentID, basic_info::idType subjectID);										//ɾ��ѧ��ѧϰ��ĳѧ�Ƴɼ�
	operr ChangeStudentScore(basic_info::idType studentID, basic_info::idType subjectID, basic_info::scoreType newScore);		//����ѧ������
	operr ChangeStudentClass(basic_info::idType studentID, basic_info::idType newClassID);										//����ѧ���༶
	operr ChangeStudentID(basic_info::idType srcID, basic_info::idType newID);													//����ѧ��ID

	//���ڴ浵

	//�浵������һ��������¼����Ķ�����Ϣ�����ж������ʧ����ָ��ΪNULL����ʼ����ѧ��ʱָ��Ϊ-1����0xffffffff
	std::list<basic_info*> ReadFromFile(const std::string& fileName);

	//����
	bool SaveToFile(const std::string& fileName);

	//��������
	~Info() { Clear(); }

private: 
	std::map<basic_info::idType, Student*> studentList;			//����ѧ���б�
	std::map<basic_info::idType, Subject*> subjectList;			//����ѧ���б�
	std::map<basic_info::idType, Class*> classList;				//���а༶�б�

	modeType mode;												//��Ϣģʽ
}; 

#endif	//#ifndef INFO_H
