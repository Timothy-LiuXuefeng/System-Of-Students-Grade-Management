
#ifndef SUBJECT_H

#define SUBJECT_H

////////////////////////////////////////////////////
/////////////////////////ѧ��///////////////////////
////////////////////////////////////////////////////

#include "basic.h"

class Subject : public basic_info							//ѧ���࣬���ѧ���ɼ�
{
public: 

	//ѧ������ڻ������
	Subject(idType id, std::string name, scoreType fullScore ,int credit = 1) 
		: basic_info(id, name, objtype::bSubject), fullScore(fullScore >= 0 ? fullScore : 0),credit(credit >= 0 ? credit : 0) {}

	//���㱾�ſ�ƽ����
	virtual scoreType GetAverage() const; 

	//��ѧ��
	bool InsertStudent(idType studentId, scoreType score); 

	//�޸�ѧ���ɼ�
	bool ChangeScore(idType studentId, scoreType score); 

	//��ȡѧ���ɼ�����û�����ѧ���򷵻�-1
	scoreType GetScore(idType studentId) const; 

	//ɾ��ѧ��
	bool DeleteStudent(idType studentId); 

	//��ȡ���ſε�����
	scoreType GetFullScore() const { return fullScore; }

	//�������ſε����֣�������ڻ������
	bool SetFullScore(basic_info::scoreType newFullScore) { return (fullScore = newFullScore >= 0 ? newFullScore : fullScore) == newFullScore; }

	//��ȡѧ��
	int GetCredit() const { return credit; }

	//����ѧ�֣�������ڻ������
	bool SetCredit(int newCredit) { return (credit = newCredit >= 0 ? newCredit : credit) == newCredit; }

	//��ȡѧ���б�
	const std::map<idType, scoreType>& GetStudentList() const { return studentList; }

	virtual std::string GetObjName() const { return std::string("Subject"); }

	virtual ~Subject() {}
private: 
	std::map<idType, scoreType> studentList;		//��¼ѧϰ���ſε�ѧ��id�����ǵķ���
	scoreType fullScore;							//��¼���ſε�����
	int credit;										//��¼���ſε�ѧ����
};


#endif		//#ifndef SUBJECT_H