#ifndef STUDENT_H

#define STUDENT_H

////////////////////////////////////////////////////////////////
////////////////////////////ѧ��/////////////////////////////////
////////////////////////////////////////////////////////////////

#include "info.h"
#include "subject.h"

class Student : public basic_info						//ѧ����
{
public:
	enum genderType
	{
		male,
		female
	};

	//���캯��
	Student(idType id, const std::string& name, genderType gender, idType classId)
		: basic_info(id, name, objType), gender(gender), classId(classId) {}

	virtual std::string GetObjName() const { return std::string("Student"); }

	genderType GetGender() const { return gender; }		//��ȡ�Ա�

	//��ת�Ա�
	void ReverseGender() { gender = (gender == genderType::male ? genderType::female : genderType::male); }

	//��ȡ�༶ID
	idType GetClassID() const { return classId; }

	//���ð༶ID
	void SetClassID(idType newClassID) { classId = newClassID; }

	//ѧϰһ����ѧ��
	bool InsertSubject(idType subjectId, scoreType score);

	//�ı����
	bool ChangeScore(idType subjectId, scoreType score);

	//ɾ��ѧ��
	bool DeleteSubject(idType subjectId);

	//��ȡѧ���б�
	const std::map<idType, scoreType>& GetSubjectList() const { return subjectList; }

	//�����ܷ�
	scoreType GetSum() const;

	//������Ч�֣�ѡ��ģʽ��Ϊ����������ģʽ��Ϊ�ܷ�
	scoreType GetValid() const { return (mode == modeType::optional) ? GetAverage() : GetSum(); }

	//�������
	virtual scoreType GetAverage() const;

	virtual ~Student() {}

protected:
	genderType gender;									//�Ա�
	std::map<idType, scoreType> subjectList;			//��¼ѧ��id�ͳɼ�
	idType classId;										//��¼�༶ID
};

 

#endif	//#ifndef STUDENT_H
