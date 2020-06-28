#ifndef BASIC_H

#define BASIC_H

////////////////////////////////////////////////////////////////
/////////////////////////��¼������Ϣ/////////////////////////////
////////////////////////////////////////////////////////////////

#include <string>
#include <set>
#include <map>

class basic_info									//������Ϣ������
{
public: 

	enum objtype									//��ʾ��������
	{
		bStudent,									//ѧ��
		bSubject,									//ѧ��
		bClass										//�༶
	}; 


	typedef int idType; 
	typedef double scoreType; 

	//���캯��
	basic_info(idType id, const std::string& name, objtype objType) : id(id), name(name), objType(objType) {}

	//����
	void SetID(idType newID) { id = newID; }							//����ID
	idType GetID() const { return id; }									//��ȡID
	std::string GetName() const { return name; }						//��ȡ����
	void SetName(const std::string& newName) { name = newName; }		//��������
	objtype GetObjType() const { return objType; }						//��ȡ��������

	//��ȡƽ�����麯��
	virtual scoreType GetAverage() const = 0;							//��ȡƽ����
	//�Ƚ�
	bool operator<(const basic_info& cmp) { return id < cmp.id; }

	//���ش���������͵��ַ���
	virtual std::string GetObjName() const = 0; 

	//��������
	virtual ~basic_info() {}

protected: 

	idType id; 
	std::string name; 
	objtype objType; 
}; 


#endif				//#ifndef BASIC_H
