
////////////////////////////////////////
//
//  �Ѿ����õĴ���
//



//
//class ClassPtr									//Class����ʹ��ָ���Сʱ�俪��
//{
//public:
//	ClassPtr(basic_info::idType id, const std::string& name)
//	{
//		_class = new Class(id, name);
//	}
//
//	ClassPtr(const ClassPtr& src)
//	{
//		_class = new Class(*src._class);
//	}
//
//	ClassPtr& operator=(const ClassPtr& src)
//	{
//		delete _class;
//		_class = new Class(*src._class);
//	}
//
//	//ָ�����
//	Class* operator->() { return _class; }
//
//
//	//�Ƚ�ָ���ѧ�ƴ�С
//	bool operator<(const ClassPtr& cmp) { return *_class < *cmp._class; }
//
//	~ClassPtr() { delete _class; }
//
//private:
//	Class* _class;
//};
//
//
//
//
//
//class StudentPtr									//Student����ʹ��ָ���Сʱ��Ϳռ俪��
//{
//public:
//	StudentPtr(basic_info::idType id, const std::string& name, People::genderType gender, basic_info::idType classId)
//	{
//		_student = new Student(id, name, gender, classId);
//	}
//
//	StudentPtr(const StudentPtr& src)
//	{
//		_student = new Student(*src._student);
//	}
//
//	StudentPtr& operator=(const StudentPtr& src)
//	{
//		delete _student;
//		_student = new Student(*src._student);
//	}
//
//	//ָ�����
//	Student* operator->() { return _student; }
//
//
//	//�Ƚ�ָ���ѧ�ƴ�С
//	bool operator<(const StudentPtr& cmp) { return *_student < *cmp._student; }
//
//	~StudentPtr() { delete _student; }
//
//private:
//	Student* _student;
//};
//
//
//
//
//class SubjectPtr									//Subject����ʹ��ָ���Сʱ�俪��
//{
//public:
//	SubjectPtr(basic_info::idType id, const std::string& name, int credit = 1)
//	{
//		_subject = new Subject(id, name, credit);
//	}
//
//	SubjectPtr(const SubjectPtr& src)
//	{
//		_subject = new Subject(*src._subject);
//	}
//
//	SubjectPtr& operator=(const SubjectPtr& src)
//	{
//		delete _subject;
//		_subject = new Subject(*src._subject);
//	}
//
//	//ָ�����
//	Subject* operator->() { return _subject; }
//
//
//	//�Ƚ�ָ���ѧ�ƴ�С
//	bool operator<(const SubjectPtr& cmp) { return *_subject < *cmp._subject; }
//
//	~SubjectPtr() { delete _subject; }
//
//private:
//	Subject* _subject;
//};
//
//
//
