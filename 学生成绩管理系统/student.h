#ifndef STUDENT_H

#define STUDENT_H

////////////////////////////////////////////////////////////////
//
//  ѧ����
//

#include "basic.h"

class Student : public obj_base						//ѧ����
{
public:
	enum genderType
	{
		male,
		female
	};

	//���캯��
	Student(idType id, const std::string& name, genderType gender, idType classId)
		: obj_base(id, name, objType, ""), gender(gender), classId(classId) {}

	virtual std::string GetObjName() const { return std::string("Student"); }

	genderType GetGender() const { return gender; }		//��ȡ�Ա�

	//��ת�Ա�
	void ReverseGender() { gender = (gender == genderType::male ? genderType::female : genderType::male); }

	//��ȡ�༶ID
	idType GetClassID() const { return classId; }

	//���ð༶ID
	void SetClassID(idType newClassID) { classId = newClassID; }

	//ѧϰһ���¿γ�
	bool InsertSubject(idType subjectId, scoreType score);

	//�ı����
	bool ChangeScore(idType subjectId, scoreType score);

	//ɾ���γ�
	bool DeleteSubject(idType subjectId);

	//��ȡ�γ��б�
	const std::map<idType, scoreType>& GetSubjectList() const { return subjectList; }

	virtual ~Student() {}

private:
	genderType gender;									//�Ա�
	std::map<idType, scoreType> subjectList;			//��¼�γ�id�ͳɼ�
	idType classId;										//��¼�༶ID
};

 

#endif	//#ifndef STUDENT_H
