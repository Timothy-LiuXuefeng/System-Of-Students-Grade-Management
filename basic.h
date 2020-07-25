#ifndef BASIC_H

#define BASIC_H

////////////////////////////////////////////////////////////////
//
//  ��¼������Ϣ
//

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

	
	//�Ƚ�
	bool operator<(const basic_info& cmp) { return id < cmp.id; }

	//���ش���������͵��ַ���
	virtual std::string GetObjName() const = 0; 

	//��������
	virtual ~basic_info() {}

protected: 

	idType id;						//ID
	std::string name;				//����
	objtype objType;				//��������
}; 

class obj_base : public basic_info										//������࣬��¼����������ķ���
{
public: 
	obj_base(idType id, const std::string& name, objtype objType, const std::string& appendInfo) : basic_info(id, name, objType), appendInfo(appendInfo) {}
	const std::string& GetAppendInfo() const { return appendInfo; }
	void SetAppendInfo(const std::string& newAppendInfo) { appendInfo = newAppendInfo; }
private: 
	std::string appendInfo;												//��Ÿ�����Ϣ
};


#endif				//#ifndef BASIC_H
