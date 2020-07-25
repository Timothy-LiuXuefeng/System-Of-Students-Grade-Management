#ifndef CLASS_H

#define CLASS_H

////////////////////////////////////////////
//
//  �༶��
//

#include "student.h"

class Class : public obj_base			//�༶��
{
public: 
	Class(idType id, const std::string& name)
		: obj_base(id, name, objtype::bClass, "") {}
	virtual std::string GetObjName() const { return std::string("Class"); }

	//����ѧ��
	bool InsertStudent(idType studentId); 
	
	//ɾ��ѧ��
	bool DeleteStudent(idType studentId); 

	const std::set<idType>& GetStudentList() const { return studentList; }

	virtual ~Class() {}

private: 
	std::set<idType> studentList;		//ѧ���б�
}; 




#endif	//#ifndef CLASS_H
