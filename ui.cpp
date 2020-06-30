#include "ui.h"

std::streamsize UI::nameLength = 25; 
std::streamsize UI::idLength = 15; 
std::streamsize UI::scoreLength = 8; 

HANDLE hConsoleOutPut; 

void UI::StartProcedure()
{
	system("cls");
	SET_CONSOLE_MAIN_COLOR(); 
	hConsoleOutPut = GetStdHandle(STD_OUTPUT_HANDLE); 
	std::cout << "��ӭʹ��ѧ����Ϣ����ϵͳ��" << std::endl;
}

void UI::EndProcedure()
{
	ChangeInfo::Clear(); 
	system("cls");
	std::cout << "��л����ʹ��" << std::endl;
	system("pause");
}

bool UI::ChooseMode()
{
	char buf = 0; 
	while (true)
	{
		std::cout << "��������Ҫʹ�õ�ģʽ��" << std::endl << "A.����ģʽ����������������׶κͲ��ָ߼���ѧ��\nB.ѧ��ģʽ�������ڲ���ѧ���Ƹ����Լ��ߵ�ѧУ��\nC.����...\nD.�˳�����" << std::endl;
		std::cin >> buf; 
		std::cin.clear(); 
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		switch (buf)
		{
		case 'a': case 'A':
			mode = modeType::compulsory;
			return true;
		case 'b': case'B':
			mode = modeType::optional;
			return true;
		case 'c': case 'C':
			std::cout << std::endl << separator << std::endl << std::endl << about << std::endl << std::endl << separator << std::endl << std::endl;
			break;
		case 'd': case 'D':
			return false;
		default:
			SET_TEXT_WARNING(); 
			std::cout << "����Ƿ���" << std::endl;
			SET_TEXT_NORMAL(); 
		}
	}
}

void UI::OptionalSystem()
{
	system("cls");
	while (true)
	{
		std::cout << "��ǰ��ѧ���ɼ�����ϵͳѡ��ģʽ" << std::endl;
		std::cout << "A.������һ��\nB.��ʾ��ǰ������ѧ��\nC.�������ѧ���ɼ�\nD.���ĳѧ��ѧ���ɼ�\nE.���ĳ�༶ѧ���ɼ�\nF.������а༶\nG.���\nH.����\nI.����ѧ���ɼ�\nJ.ɾ��\nK.��ȡ�浵���������ǰ�ɼ��⣩\nL.����...\nM.�����������" << std::endl;
		char buf = 0;
		std::cin >> buf;
		std::cin.clear(); 
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
		switch (buf)
		{
		case 'A': case'a':
			SET_TEXT_WARNING(); 
			std::cout << "������һ����ʹ����ȫ����ʧ�������ȷ�����������Ѿ����棬��ȷ��Ҫ������? (Y/n): " << std::flush; 
			buf = 0;
			while (true)
			{
				std::cin >> buf; 
				std::cin.clear(); 
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
				switch (buf)
				{
				case 'Y': case 'y': case 'N': case 'n': 
					break; 
				default: 
					std::cout << "����Ƿ�! ������һ����ʹ������ȫ����ʧ����ȷ����? (Y/n): " << std::flush; 
					continue; 
				}
				break; 
			}
			SET_TEXT_NORMAL();
			if (buf == 'Y' || buf == 'y')
			{
				ChangeInfo::Clear(); 
				return; 
			}
			break; 
		case 'B': case 'b':
			PrintSubject(); 
			break; 
		case 'C': case'c': 
			std::cout << "�Ƿ񰴳ɼ�����?(Y/n)" << std::flush; 
			while (true)
			{
				buf = 0; 
				std::cin >> buf; 
				std::cin.clear(); 
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
				if (buf == 'Y' || buf == 'y') { PrintStudent(true); break; }
				else if (buf == 'N' || buf == 'n') { PrintStudent(false); break; }
				else
				{
					SET_TEXT_WARNING(); std::cout << "����Ƿ����Ƿ񰴳ɼ�����?(Y/n)" << std::flush; SET_TEXT_NORMAL(); 
				}
			}
			break; 
		case 'D': case 'd': 
		{
			basic_info::idType subjectID; 
			std::cout << "�������ѧ�Ƶ�ID: " << std::flush; 
			while (!(std::cin >> subjectID))
			{
				std::cin.clear(); 
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
				SET_TEXT_WARNING();
				std::cout << "����Ƿ��������������ѧ�Ƶ�ID: " << std::flush; 
				SET_TEXT_NORMAL(); 
			}
			std::cout << "�Ƿ񰴳ɼ�����?(Y/n)" << std::flush;
			while (true)
			{
				buf = 0; 
				std::cin >> buf;
				std::cin.clear(); 
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				if (buf == 'Y' || buf == 'y') { PrintSubjectStudent(subjectID, true); break; }
				else if (buf == 'N' || buf == 'n') { PrintSubjectStudent(subjectID, false); break; }
				else
				{
					SET_TEXT_WARNING(); std::cout << "����Ƿ����Ƿ񰴳ɼ�����?(Y/n)" << std::flush; SET_TEXT_NORMAL();
				}
			}
			break;
		}
		case 'E': case 'e': 
		{
			basic_info::idType classID;
			std::cout << "������ð༶��ID: " << std::flush;
			while (!(std::cin >> classID))
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				SET_TEXT_WARNING();
				std::cout << "����Ƿ������������룡" << std::endl;
				SET_TEXT_NORMAL();
			}
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
			std::cout << "�Ƿ񰴳ɼ�����?(Y/n)" << std::flush;
			while (true)
			{
				buf = 0;
				std::cin >> buf;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				if (buf == 'Y' || buf == 'y') { PrintClassStudent(classID, true); break; }
				else if (buf == 'N' || buf == 'n') { PrintClassStudent(classID, false); break; }
				else
				{
					SET_TEXT_WARNING(); std::cout << "����Ƿ����Ƿ񰴳ɼ�����?(Y/n)" << std::flush; SET_TEXT_NORMAL();
				}
			}
			break;
		}
		case 'F': case 'f': 
		{
			PrintClass(); 
			break; 
		}
		case 'G': case 'g': 
		{
			std::cout << "��ѡ��: A.������һ��\tB.�����ѧ��\tC.����°༶\tD.�����ѧ��\tE.���Ѵ��ڵ�ѧ����ӿγ�" << std::endl; 
			while (true)
			{
				buf = 0;
				std::cin >> buf;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				switch (buf)
				{
				case 'A': case 'a': 
					break; 
				case 'B': case 'b': 
				{
					addNewSubject: 
					basic_info::idType id; 
					basic_info::scoreType fullScore; 
					int credit; 
					std::string name; 
					std::cout << "��������ӵ���ѧ�Ƶ�ID: " << std::flush;
					while (!(std::cin >> id) || info.GetSubjectList().find(id) != info.GetSubjectList().end())
					{
						SET_TEXT_WARNING();
						if(std::cin) std::cout << "�˰༶ID�Ѿ���ռ�ã���������ӵ���ѧ�Ƶ�ID: " << std::flush; 
						else std::cout << "����Ƿ�����������ӵ���ѧ�Ƶ�ID: " << std::flush; 
						SET_TEXT_NORMAL(); 
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

					}
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
					std::cout << "��������ӵ���ѧ�Ƶ�����: " << std::flush; 
					std::getline(std::cin, name); 
					std::cout << "��ֱ�������ӵ���ѧ�Ƶ���������ѧ����: " << std::endl; 
					while (!(std::cin >> fullScore >> credit))
					{
						std::cin.clear(); 
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
						SET_TEXT_WARNING();
						std::cout << "����Ƿ�����ֱ�������ӵ���ѧ�Ƶ���������ѧ����: " << std::endl; 
						SET_TEXT_NORMAL();
					}
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
					if (ChangeInfo::InsertSubject(id, name, fullScore, credit))
					{
						SET_TEXT_SUCCESS();
						std::cout << "�����ѧ�Ƴɹ���" << std::endl;
						SET_TEXT_NORMAL();
					}
					else
					{
						SET_TEXT_WARNING();
						std::cout << "���ʧ�ܣ�δ֪����" << std::endl; 
						SET_TEXT_NORMAL();
					}
					std::cout << "�Ƿ�������?(Y/n): " << std::flush; 
					buf = 0; 
					std::cin >> buf; 
					std::cin.clear(); 
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
					if (buf == 'Y' || buf == 'y') goto addNewSubject; 
					break; 
				}
				case 'C': case'c': 
				{
					addNewClass: 
					basic_info::idType id;
					std::string name;
					std::cout << "��������ӵ��°༶��ID: " << std::flush; 
					while (!(std::cin >> id) || info.GetClassList().find(id) != info.GetClassList().end())
					{
						SET_TEXT_WARNING();
						if(std::cin)
							std::cout << "�˰༶ID�Ѿ���ռ�ã���������ӵ��°༶��ID: " << std::flush; 
						else std::cout << "����Ƿ�����������ӵ��°༶��ID: " << std::flush;
						SET_TEXT_NORMAL();
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "��������ӵ��°༶������: " << std::flush;
					std::getline(std::cin, name);
					if (ChangeInfo::InsertClass(id, name))
					{
						SET_TEXT_SUCCESS(); std::cout << "����°༶�ɹ���" << std::endl; SET_TEXT_NORMAL(); 
					}
					else
					{
						SET_TEXT_WARNING(); std::cout << "���ʧ�ܣ�δ֪����" << std::endl; SET_TEXT_NORMAL(); 
					}
					std::cout << "�Ƿ�������?(Y/n): " << std::flush;
					buf = 0;
					std::cin >> buf;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					if (buf == 'Y' || buf == 'y') goto addNewClass;
					break; 
				}
				case 'D': case'd': 
				{
					addNewStudent: 
					basic_info::idType id, classID;
					std::string name;
					Student::genderType gender = Student::genderType::male; 
					std::cout << "��������ӵ���ѧ����ID: " << std::flush;
					while (!(std::cin >> id) || info.GetStudentList().find(id) != info.GetStudentList().end())
					{
						SET_TEXT_WARNING(); 
						if (std::cin)
							std::cout << "��ѧ��ID�Ѿ���ռ�ã���������ӵ��°༶��ID: " << std::flush; 
						else std::cout << "����Ƿ�����������ӵ���ѧ����ID: " << std::flush;
						SET_TEXT_NORMAL(); 
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "��������ӵ���ѧ��������: " << std::flush;
					std::getline(std::cin, name);
					std::cout << "������ѧ�����Ա�(m/f: m-male, f-female): " << std::flush; 
					buf = 0; 
					while(true)
					{
						std::cin >> buf; 
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
						switch (buf)
						{
						case 'M': case'm': 
							gender = Student::genderType::male; 
							break; 
						case 'F': case'f': 
							gender = Student::genderType::female; 
							break; 
						default: 
							SET_TEXT_WARNING(); 
							std::cout << "����Ƿ���������ѧ�����Ա�(m/f: m-male, f-female): " << std::flush; 
							SET_TEXT_NORMAL(); 
							continue; 
						}
						break; 
					}; 
					std::cout << "�������ѧ�������༶��ID: " << std::flush; 
					while (!(std::cin >> classID))
					{
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						SET_TEXT_WARNING(); 
						std::cout << "����Ƿ����������ѧ�������༶��ID: " << std::flush;
						SET_TEXT_NORMAL(); 
					}
					if (ChangeInfo::InsertStudent(id, name, gender, classID))
					{
						SET_TEXT_SUCCESS(); std::cout << "�����ѧ���ɹ���" << std::endl; SET_TEXT_NORMAL();
					}
					else
					{
						SET_TEXT_WARNING(); std::cout << "���ʧ�ܣ������ڴ˰༶��" << std::endl; SET_TEXT_NORMAL(); 
					}
					std::cout << "�Ƿ�������?(Y/n): " << std::flush;
					buf = 0;
					std::cin >> buf;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					if (buf == 'Y' || buf == 'y') goto addNewStudent;
					break; 
				}
				case 'E': case 'e': 
				{
					addNewStudentSubject: 
					basic_info::idType studentID, subjectID; 
					basic_info::scoreType score; 
					std::cout << "����������ѧ����ID��ѧ�Ƶ�ID��ѧ�Ƶķ���: " << std::endl; 
					while (true)
					{
						std::cin >> studentID >> subjectID >> score; 
						if (std::cin.fail())
						{
							SET_TEXT_WARNING(); 
							std::cout << "����Ƿ�������������ѧ����ID��ѧ�Ƶ�ID��ѧ�Ƶķ���: " << std::endl; 
							SET_TEXT_NORMAL(); 
							std::cin.clear(); 
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
							continue; 
						}
						switch (ChangeInfo::AddStudentSubject(studentID, subjectID, score))
						{
						case ChangeInfo::operr::success: 
							SET_TEXT_SUCCESS(); 
							std::cout << "�����ɹ���" << std::endl; 
							SET_TEXT_NORMAL(); 
							break; 
						case ChangeInfo::operr::has_studied: 
							SET_TEXT_WARNING(); 
							std::cout << "��ѧ���Ѿ��������ſγ̵ĳɼ�" << std::endl; 
							SET_TEXT_NORMAL(); 
							break; 
						case ChangeInfo::operr::no_student: 
							SET_TEXT_WARNING();
							std::cout << "����������ѧ��" << std::endl;
							SET_TEXT_NORMAL();
							break; 
						case ChangeInfo::operr::no_subject: 
							SET_TEXT_WARNING();
							std::cout << "����������ѧ��" << std::endl;
							SET_TEXT_NORMAL();
							break; 
						}
						break; 
					}; 
					std::cout << "�Ƿ�������?(Y/n): " << std::flush;
					buf = 0;
					std::cin >> buf;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					if (buf == 'Y' || buf == 'y') goto addNewStudentSubject;
					break; 
				}
				default: 
					SET_TEXT_WARNING(); 
					std::cout << "����Ƿ���" << std::endl; 
					SET_TEXT_NORMAL();
					continue; 
				}
				break; 
			}
			break; 
		}
		case 'H': case 'h': 
		{
			std::cout << "��ѡ��: A.������һ��\tB.����ѧ����Ϣ\tC.���İ༶��Ϣ\tD.����ѧ����Ϣ" << std::endl; 
			buf = 0;
			std::cin >> buf;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			switch (buf)
			{
			case 'A': case 'a':
				break;
			case 'B': case 'b': 
				std::cout << "��ѡ��A.����ѧ��ID\tB.����ѧ������\tC.�޸�ѧ������\tD.�޸�ѧ��ѧ��\tE.ȡ��" << std::endl; 
				buf = 0; 
				std::cin >> buf; 
				std::cin.clear(); 
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
				switch (buf)
				{
				case 'A': case 'a': 
				{
					basic_info::idType srcID, newID; 
					std::cout << "����������ѧ��ԭID����ID: " << std::endl; 
					while (!(std::cin >> srcID >> newID))
					{
						std::cin.clear(); 
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
						SET_TEXT_WARNING();
						std::cout << "����Ƿ�������������ѧ��ԭID����ID: " << std::endl;
						SET_TEXT_NORMAL();
					}
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					switch (ChangeInfo::ChangeSubjectID(srcID, newID))
					{
					case ChangeInfo::operr::success: 
						SET_TEXT_SUCCESS();
						std::cout << "�޸ĳɹ���" << std::endl;
						SET_TEXT_NORMAL();
						break; 
					case ChangeInfo::operr::no_subject: 
						SET_TEXT_WARNING();
						std::cout << "��ѧ�Ʋ����ڣ�" << std::endl;
						SET_TEXT_NORMAL();
						break; 
					case ChangeInfo::operr::subject_exist: 
						SET_TEXT_WARNING();
						std::cout << "��ID�ѱ�ռ�ã��޸�ʧ�ܣ�" << std::endl;
						SET_TEXT_NORMAL(); 
						break; 
					}
					break;
				}
				case 'B': case 'b': 
				{
					basic_info::idType id; 
					std::string name; 
					std::cout << "������Ҫ�޸����Ƶ�ѧ��ID: " << std::flush; 
					while (!(std::cin >> id) || info.GetSubjectList().find(id) == info.GetSubjectList().end())
					{
						SET_TEXT_WARNING(); 
						if (std::cin) std::cout << "��ѧ�Ʋ����ڣ�����������Ҫ�޸����Ƶ�ѧ��ID: " << std::flush;
						else std::cout << "����Ƿ�������������Ҫ�޸����Ƶ�ѧ��ID: " << std::flush; 
						SET_TEXT_NORMAL(); 
						std::cin.clear(); 
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "�������µ�ѧ������: " << std::flush; 
					std::getline(std::cin, name); 
					info.GetSubjectList().at(id)->SetName(name); 
					break; 
				}
				case 'C': case 'c': 
				{
					basic_info::idType id; 
					basic_info::scoreType fullScore; 
					std::cout << "����������Ҫ�޸����Ƶ�ѧ��ID������: " << std::endl;
					while (!(std::cin >> id >> fullScore) || info.GetSubjectList().find(id) == info.GetSubjectList().end())
					{
						SET_TEXT_WARNING();
						if (std::cin) std::cout << "û�и�ID�Ŀγ̣�����������Ҫ�޸����Ƶ�ѧ��ID������: " << std::flush; 
						else std::cout << "����Ƿ�������������Ҫ�޸����Ƶ�ѧ��ID������: " << std::flush;
						SET_TEXT_NORMAL();
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
					}
					info.GetSubjectList().at(id)->SetFullScore(fullScore); 
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
					break; 
				}
				case 'D': case 'd':
				{
					basic_info::idType id;
					int credit;
					std::cout << "����������Ҫ�޸����Ƶ�ѧ��ID��ѧ��: " << std::endl;
					while (!(std::cin >> id >> credit) || info.GetSubjectList().find(id) == info.GetSubjectList().end())
					{
						SET_TEXT_WARNING();
						if (std::cin) std::cout << "û�и�ID��ѧ�ƣ�����������Ҫ�޸����Ƶ�ѧ��ID����ѧ��: " << std::flush;
						else std::cout << "����Ƿ�������������Ҫ�޸����Ƶ�ѧ��ID��ѧ��: " << std::flush;
						SET_TEXT_NORMAL();
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					info.GetSubjectList().at(id)->SetCredit(credit);
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					break;
				}
				default: 
					SET_TEXT_WARNING();
					std::cout << "����Ƿ���" << std::endl;
					SET_TEXT_NORMAL();
				case 'E': case 'e':
					break; 
				}
				break; 
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
			case 'C': case 'c':
				std::cout << "��ѡ��A.���İ༶ID\tB.���İ༶����\tC.ȡ��" << std::endl;
				buf = 0; 
				std::cin >> buf;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				switch (buf)
				{
				case 'A': case 'a':
				{
					basic_info::idType srcID, newID;
					std::cout << "����������༶ԭID����ID: " << std::endl;
					while (!(std::cin >> srcID >> newID))
					{
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						SET_TEXT_WARNING();
						std::cout << "����Ƿ����޸�ʧ�ܣ�" << std::endl;
						SET_TEXT_NORMAL();
					}
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					switch (ChangeInfo::ChangeClassID(srcID, newID))
					{
					case ChangeInfo::operr::success:
						SET_TEXT_SUCCESS();
						std::cout << "�޸ĳɹ���" << std::endl;
						SET_TEXT_NORMAL();
						break;
					case ChangeInfo::operr::no_class:
						SET_TEXT_WARNING();
						std::cout << "�ð༶�����ڣ�" << std::endl;
						SET_TEXT_NORMAL();
						break;
					case ChangeInfo::operr::class_exist:
						SET_TEXT_WARNING();
						std::cout << "��ID�ѱ�ռ�ã��޸�ʧ�ܣ�" << std::endl;
						SET_TEXT_NORMAL();
						break;
					}
					break;
				}
				case 'B': case 'b':
				{
					basic_info::idType id;
					std::string name;
					std::cout << "������Ҫ�޸����Ƶİ༶ID: " << std::flush;
					while (!(std::cin >> id) || info.GetClassList().find(id) == info.GetClassList().end())
					{
						SET_TEXT_WARNING();
						if (std::cin) std::cout << "�ð༶�����ڣ�����������Ҫ�޸����Ƶİ༶ID: " << std::flush;
						else std::cout << "����Ƿ�������������Ҫ�޸����Ƶİ༶ID: " << std::flush;
						SET_TEXT_NORMAL();
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "�������µİ༶����: " << std::flush;
					std::getline(std::cin, name);
					info.GetClassList().at(id)->SetName(name);
					break;
				}
				default:
					SET_TEXT_WARNING();
					std::cout << "����Ƿ���" << std::endl;
					SET_TEXT_NORMAL();
				case 'C': case 'c': 
					break;
				}
				break; 
			case 'D': case 'd': 
				std::cout << "��ѡ��A.����ѧ��ID\tB.����ѧ������\tC.����ѧ���Ա�\tD.����ѧ���༶\tE.����ѧ������\tF.ȡ��" << std::endl;
				buf = 0;
				std::cin >> buf;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
				switch (buf)
				{
				case 'A': case 'a': 
				{
					basic_info::idType srcID, newID;
					std::cout << "����������ѧ��ԭID����ID: " << std::endl;
					while (!(std::cin >> srcID >> newID))
					{
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						SET_TEXT_WARNING();
						std::cout << "����Ƿ����޸�ʧ�ܣ�" << std::endl;
						SET_TEXT_NORMAL();
					}
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					switch (ChangeInfo::ChangeStudentID(srcID, newID))
					{
					case ChangeInfo::operr::success:
						SET_TEXT_SUCCESS();
						std::cout << "�޸ĳɹ���" << std::endl;
						SET_TEXT_NORMAL();
						break;
					case ChangeInfo::operr::no_student:
						SET_TEXT_WARNING();
						std::cout << "��ѧ�������ڣ�" << std::endl;
						SET_TEXT_NORMAL();
						break;
					case ChangeInfo::operr::student_exist:
						SET_TEXT_WARNING();
						std::cout << "��ID�ѱ�ռ�ã��޸�ʧ�ܣ�" << std::endl;
						SET_TEXT_NORMAL();
						break;
					}
					break; 
				}
				case 'B': case 'b': 
				{
					basic_info::idType id; 
					std::string name; 
					std::cout << "��������Ҫ����������ѧ��ID: " << std::flush; 
					while (!(std::cin >> id) || info.GetStudentList().find(id) == info.GetStudentList().end())
					{
						SET_TEXT_WARNING();
						if (std::cin) std::cout << "��ѧ�������ڣ�������������Ҫ����������ѧ��ID: " << std::endl; 
						else std::cout << "����Ƿ���������������Ҫ����������ѧ��ID: " << std::endl; 
						SET_TEXT_NORMAL();
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					std::cout << "������ѧ����������: " << std::flush;
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
					std::getline(std::cin, name); 
					info.GetStudentList().at(id)->SetName(name); 
					SET_TEXT_SUCCESS(); 
					std::cout << "����ѧ�������ɹ���" << std::endl; 
					SET_TEXT_NORMAL();
					break; 
				}
				case 'C': case 'c': 
				{
					basic_info::idType id; 
					std::cout << "������Ҫ�����Ա��ѧ��ID: " << std::flush; 
					while (!(std::cin >> id) || info.GetStudentList().find(id) == info.GetStudentList().end())
					{
						SET_TEXT_WARNING(); 
						if (std::cin) std::cout << "����Ƿ�������������Ҫ�����Ա��ѧ��ID: " << std::flush;
						else std::cout << "��ѧ�������ڣ�����������Ҫ�����Ա��ѧ��ID: " << std::flush; 
						SET_TEXT_NORMAL(); 
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "��ǰѧ������: " << info.GetStudentList().at(id)->GetName() << ", ѧ���Ա�: " 
						<< (info.GetStudentList().at(id)->GetGender() == Student::genderType::male ? "��" : "Ů") << std::endl; 
					std::cout << "��ȷ��Ҫ����ѧ���Ա���? (Y/n): " << std::flush; 
					buf = 0; 
					while(true)
					{
						std::cin >> buf; 
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
						switch (buf)
						{
						case 'Y': case 'y': 
							info.GetStudentList().at(id)->ReverseGender(); 
							SET_TEXT_SUCCESS();
							std::cout << "�޸��Ա�ɹ���" << std::endl;
							SET_TEXT_NORMAL();
							break; 
						case 'N': case 'n': 
							SET_TEXT_SUCCESS();
							std::cout << "��ȡ�����Ա��޸�" << std::endl;
							SET_TEXT_NORMAL();
							break; 
						default: 
							SET_TEXT_WARNING();
							std::cout << "����Ƿ�����ȷ��Ҫ����ѧ���Ա���? (Y/n): " << std::flush; 
							SET_TEXT_NORMAL();
							continue; 
						}
						break; 
					}
					break; 
				}
				case 'D': case 'd': 
				{
					basic_info::idType studentID, classID; 
					std::cout << "����������ѧ��ID���°༶��ID: " << std::endl; 
					while (!(std::cin >> studentID >> classID))
					{
						SET_TEXT_WARNING(); 
						std::cout << "����Ƿ�������������ѧ��ID���°༶��ID: " << std::endl; 
						SET_TEXT_NORMAL(); 
						std::cin.clear(); 
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
					switch (ChangeInfo::ChangeStudentClass(studentID, classID))
					{
					case ChangeInfo::operr::success:
						SET_TEXT_SUCCESS();
						std::cout << "�޸ĳɹ���" << std::endl;
						SET_TEXT_NORMAL();
						break;
					case ChangeInfo::operr::no_student: 
						SET_TEXT_WARNING();
						std::cout << "�޸�ʧ�ܣ���ѧ�������ڣ�" << std::endl;
						SET_TEXT_NORMAL(); 
						break; 
					case ChangeInfo::operr::no_class:
						SET_TEXT_WARNING();
						std::cout << "�޸�ʧ�ܣ��°༶�����ڣ�" << std::endl;
						SET_TEXT_NORMAL();
						break;
					}
					break; 
				}
				case 'E': case 'e':
				{
					basic_info::idType studentID, subjectID;
					basic_info::scoreType newScore; 
					std::cout << "����������ѧ��ID��Ҫ���ĵ�ѧ��ID�Լ��µķ���: " << std::endl;
					while (!(std::cin >> studentID >> subjectID >> newScore))
					{
						SET_TEXT_WARNING();
						std::cout << "����Ƿ�������������ѧ��ID��Ҫ���ĵ�ѧ��ID�Լ��µķ���: " << std::endl;
						SET_TEXT_NORMAL();
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
					switch (ChangeInfo::ChangeStudentScore(studentID, subjectID, newScore))
					{
					case ChangeInfo::operr::success:
						SET_TEXT_SUCCESS();
						std::cout << "�޸ĳɹ���" << std::endl;
						SET_TEXT_NORMAL();
						break;
					case ChangeInfo::operr::no_student:
						SET_TEXT_WARNING();
						std::cout << "�޸�ʧ�ܣ���ѧ�������ڣ�" << std::endl;
						SET_TEXT_NORMAL();
						break;
					case ChangeInfo::operr::no_subject:
						SET_TEXT_WARNING();
						std::cout << "�޸�ʧ�ܣ���ѧ��û������ѧ�Ƶĳɼ���" << std::endl;
						SET_TEXT_NORMAL();
						break;
					}
					break;
				}
				default: 
					SET_TEXT_WARNING();
					std::cout << "����Ƿ���" << std::endl;
					SET_TEXT_NORMAL();
				case 'F': case 'f':
					break;
				}
				break; 
			default: 
				SET_TEXT_WARNING(); 
				std::cout << "����Ƿ���" << std::endl; 
				SET_TEXT_NORMAL(); 
			}
			break; 
		}
		case 'I': case 'i': 
		{
			std::cout << "��ѡ��: A.������һ��\tB.����ID����\tC.������������" << std::endl; 
			buf = 0; 
			while (true)
			{
				std::cin >> buf; 
				std::cin.clear(); 
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
				switch (buf)
				{
				case 'A': case 'a':
					break;
				case 'B': case 'b': 
				{
					basic_info::idType studentID; 
					std::cout << "��������Ҫ���ҵ�ѧ��ID: " << std::flush; 
					while (!(std::cin >> studentID))
					{
						SET_TEXT_WARNING();
						std::cout << "����Ƿ�����������Ҫ���ҵ�ѧ��ID: " << std::flush; 
						SET_TEXT_NORMAL();
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					std::map<basic_info::idType, Student*>::const_iterator itr = info.GetStudentList().find(studentID); 
					if (itr == info.GetStudentList().end())
					{
						SET_TEXT_WARNING();
						std::cout << "��Ҫ�ҵ�ѧ��������" << std::endl;
						SET_TEXT_NORMAL();
					}
					else
					{
						PrintStudentInfoHead(false); 
						PrintStudentInfo(info.GetStudentList().at(studentID), 0); 
					}
					break; 
				}
				case 'C': case 'c': 
				{
					std::string name; 
					bool exist = false; 
					std::cout << "��������Ҫ���ҵ�ѧ������: " << std::flush; 
					std::getline(std::cin, name); 
					for (std::map<basic_info::idType, Student*>::const_iterator itr = info.GetStudentList().begin();
						itr != info.GetStudentList().end(); ++itr)
					{
						if (itr->second->GetName() == name)
						{
							if (!exist)
							{
								PrintStudentInfoHead(false); 
								exist = true; 
							}
							PrintStudentInfo(itr->second, 0); 
						}
					}
					if (!exist)
					{
						SET_TEXT_WARNING();
						std::cout << "��Ҫ�ҵ�ѧ��������" << std::endl;
						SET_TEXT_NORMAL(); 
					}
					break; 
				}
				default: 
					SET_TEXT_WARNING();
					std::cout << "����Ƿ�����ѡ��: A.������һ��\tB.����ID����\tC.������������" << std::endl; 
					SET_TEXT_NORMAL();
					continue; 
				}
				break; 
			}
			break; 
		}
		case 'J': case 'j':
		{
			std::cout << "��ѡ��: A.ɾ��ѧ��\tB.ɾ���༶\tC.ɾ��ѧ��\tD.ɾ��ѧ��ѧϰ��ĳѧ�Ƴɼ�\tE.������һ��" << std::endl; 
			buf = 0; 
			while (true)
			{
				std::cin >> buf;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				switch (buf)
				{
				case 'A': case 'a':
					break;
				case 'B': case 'b': 
				{
					delSubject: 
					basic_info::idType id; 
					std::cout << "��������Ҫɾ����ѧ��ID: " << std::flush; 
					while (!(std::cin >> id))
					{
						SET_TEXT_WARNING();
						std::cout << "����Ƿ���������������Ҫɾ����ѧ��ID: " << std::flush;
						SET_TEXT_NORMAL(); 
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
					}
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
					SET_TEXT_WARNING(); 
					std::cout << "������������ɾ�����ѧ����ص�������Ϣ������ѧ���ĳɼ�����ȷ��Ҫ��������?(Y/n): " << std::flush; 
					SET_TEXT_NORMAL(); 
					buf = 0; 
					while (true)
					{
						std::cin >> buf; 
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
						switch (buf)
						{
						case 'Y': case 'y': 
							if (ChangeInfo::DeleteSubject(id))
							{
								SET_TEXT_SUCCESS(); std::cout << "�ɹ�ɾ��ѧ��: " << id << std::endl; SET_TEXT_NORMAL();
							}
							else
							{
								SET_TEXT_WARNING(); std::cout << "ɾ��ʧ�ܣ���ѧ�Ʋ����ڣ�" << std::endl; SET_TEXT_NORMAL();
							}
							break; 
						case 'N': case 'n': 
							SET_TEXT_SUCCESS();
							std::cout << "��ȡ��ɾ��������" << std::endl;
							SET_TEXT_NORMAL();
							break; 
						default: 
							SET_TEXT_WARNING();
							std::cout << "����Ƿ���\nɾ����ѧ�ƻ�ɾ�����ѧ����ص�������Ϣ������ѧ���ĳɼ�����ȷ��Ҫ��������?(Y/n): " << std::flush;
							SET_TEXT_NORMAL(); 
							continue; 
						}
						break; 
					}
					std::cout << "�Ƿ����ɾ��ѧ��?(Y/n)" << std::endl; 
					buf = 0; 
					std::cin >> buf; 
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
					if (buf == 'Y' || buf == 'y') goto delSubject; 
					break; 
				}
				case 'C': case 'c': 
				{
				delClass:
					basic_info::idType id;
					std::cout << "��������Ҫɾ���İ༶ID: " << std::flush;
					while (!(std::cin >> id))
					{
						SET_TEXT_WARNING();
						std::cout << "����Ƿ���������������Ҫɾ���İ༶ID: " << std::flush;
						SET_TEXT_NORMAL();
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					SET_TEXT_WARNING();
					std::cout << "�ò������ɻָ�����ȷ��Ҫɾ���ð༶��?(Y/n): " << std::flush;
					SET_TEXT_NORMAL();
					buf = 0;
					while (true)
					{
						std::cin >> buf;
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						switch (buf)
						{
						case 'Y': case 'y':
							switch (ChangeInfo::DeleteClass(id))
							{
							case ChangeInfo::operr::success: 
								SET_TEXT_SUCCESS();
								std::cout << "�ɹ�ɾ���༶: " << id << std::endl;
								SET_TEXT_NORMAL();
								break; 
							case ChangeInfo::operr::no_class: 
								SET_TEXT_WARNING();
								std::cout << "ɾ��ʧ�ܣ��ð༶�����ڣ�" << std::endl;
								SET_TEXT_NORMAL();
								break; 
							case ChangeInfo::operr::student_exist: 
								SET_TEXT_WARNING();
								std::cout << "ɾ��ʧ�ܣ��ð༶����ѧ����ɾ��ǰ���Ƚ��༶��գ�" << std::endl;
								SET_TEXT_NORMAL();
								break; 
							}
							break;
						case 'N': case 'n':
							SET_TEXT_SUCCESS();
							std::cout << "��ȡ��ɾ��������" << std::endl;
							SET_TEXT_NORMAL();
							break;
						default:
							SET_TEXT_WARNING();
							std::cout << "����Ƿ���\nɾ���ð༶���ɻָ�����ȷ��Ҫɾ���ð༶��?(Y/n): " << std::flush;
							SET_TEXT_NORMAL();
							continue;
						}
						break;
					}
					std::cout << "�Ƿ����ɾ���༶?(Y/n)" << std::endl;
					buf = 0;
					std::cin >> buf;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					if (buf == 'Y' || buf == 'y') goto delClass;
					break; 
				}
				case 'D': case 'd': 
				{
				delStudent:
					basic_info::idType id;
					std::cout << "��������Ҫɾ����ѧ��ID: " << std::flush;
					while (!(std::cin >> id))
					{
						SET_TEXT_WARNING();
						std::cout << "����Ƿ���������������Ҫɾ����ѧ��ID: " << std::flush;
						SET_TEXT_NORMAL();
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					SET_TEXT_WARNING();
					std::cout << "������������ɾ����ѧ����������Ϣ����ȷ��Ҫ��������?(Y/n): " << std::flush;
					SET_TEXT_NORMAL();
					buf = 0;
					while (true)
					{
						std::cin >> buf;
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						switch (buf)
						{
						case 'Y': case 'y':
							if (ChangeInfo::DeleteStudent(id))
							{
								SET_TEXT_SUCCESS(); std::cout << "�ɹ�ɾ��ѧ��: " << id << std::endl; SET_TEXT_NORMAL();
							}
							else
							{
								SET_TEXT_WARNING(); std::cout << "ɾ��ʧ�ܣ���ѧ�������ڣ�" << std::endl; SET_TEXT_NORMAL();
							}
							break;
						case 'N': case 'n':
							SET_TEXT_SUCCESS();
							std::cout << "��ȡ��ɾ��������" << std::endl;
							SET_TEXT_NORMAL();
							break;
						default:
							SET_TEXT_WARNING();
							std::cout << "����Ƿ���\nɾ����ѧ��������ɾ����ѧ����������Ϣ����ȷ��Ҫ��������?(Y/n): " << std::flush;
							SET_TEXT_NORMAL();
							continue;
						}
						break;
					}
					std::cout << "�Ƿ����ɾ��ѧ��?(Y/n)" << std::endl;
					buf = 0;
					std::cin >> buf;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					if (buf == 'Y' || buf == 'y') goto delStudent;
					break; 
				}
				case 'E': case 'e':
				{
					{
					delStudentSubject:
						basic_info::idType studentID, subjectID;
						std::cout << "������������Ҫɾ���ɼ���ѧ��ID��ѧ��ID: " << std::endl;
						while (!(std::cin >> studentID >> subjectID))
						{
							SET_TEXT_WARNING();
							std::cout << "����Ƿ���������������Ҫɾ���İ༶ID: " << std::flush;
							SET_TEXT_NORMAL();
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						}
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						SET_TEXT_WARNING();
						std::cout << "�ò������ɻָ�����ȷ��Ҫɾ����ѧ���ĸÿƳɼ���?(Y/n): " << std::flush;
						SET_TEXT_NORMAL();
						buf = 0;
						while (true)
						{
							std::cin >> buf;
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							switch (buf)
							{
							case 'Y': case 'y':
								switch (ChangeInfo::DeleteStudentSubject(studentID, subjectID))
								{
								case ChangeInfo::operr::success:
									SET_TEXT_SUCCESS();
									std::cout << "�ɹ�ɾ��ѧ��: " << studentID << "��ѧ��: " << subjectID << "�ĳɼ�" << std::endl;
									SET_TEXT_NORMAL();
									break;
								case ChangeInfo::operr::no_student:
									SET_TEXT_WARNING();
									std::cout << "ɾ��ʧ�ܣ���ѧ�������ڣ�" << std::endl;
									SET_TEXT_NORMAL();
									break;
								case ChangeInfo::operr::no_subject:
									SET_TEXT_WARNING();
									std::cout << "ɾ��ʧ�ܣ���ѧ���޸�ѧ�Ƶĳɼ���" << std::endl;
									SET_TEXT_NORMAL();
									break;
								}
								break;
							case 'N': case 'n':
								SET_TEXT_SUCCESS();
								std::cout << "��ȡ��ɾ��������" << std::endl;
								SET_TEXT_NORMAL();
								break;
							default:
								SET_TEXT_WARNING();
								std::cout << "����Ƿ���\nɾ��ѧ���ɼ����ɻָ�����ȷ��Ҫɾ����ѧ���ĸÿƳɼ���?(Y/n): " << std::flush;
								SET_TEXT_NORMAL();
								continue;
							}
							break;
						}
						std::cout << "�Ƿ����ɾ���༶?(Y/n)" << std::endl;
						buf = 0;
						std::cin >> buf;
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						if (buf == 'Y' || buf == 'y') goto delStudentSubject;
						break;
					}
					break; 
				}
				default: 
					SET_TEXT_WARNING();
					std::cout << "����Ƿ�����ѡ��: A.ɾ��ѧ��\tB.ɾ���༶\tC.ɾ��ѧ��\tD.ɾ��ѧ��ѧϰ��ĳѧ�Ƴɼ�\tE.������һ��" << std::endl;
					SET_TEXT_NORMAL(); 
					continue; 
				}
				break; 
			}
			break; 
		}
		case 'K': case 'k': 
		{
			std::string fileName; 
			std::cout << "������Ҫ��ȡ���ļ�����" << std::endl; 
			std::getline(std::cin, fileName); 
			bool hasReadStudent = false;			//��¼�Ƿ�¼����ѧ��
			std::list<basic_info*> readInfo; 
			std::cout << "��ʼ�������ݣ���ȴ�..." << std::endl; 
			readInfo = ChangeInfo::ReadFromFile(fileName); 
			size_t subNum = 0, clsNum = 0, stuNum = 0, stuSubNum = 0, errNum = 0; 
			for (std::list<basic_info*>::const_iterator itr = readInfo.begin();
				itr != readInfo.end(); ++itr)
			{
				if (!(*itr))						//�������
				{
					++errNum;
					SET_TEXT_WARNING(); 
					std::cout << "�ö���������" << std::endl; 
					SET_TEXT_NORMAL(); 
					continue; 
				}
				else if (*itr == (basic_info*)(-1))	//��ʼ����ѧ��
				{
					hasReadStudent = true; 
					continue; 
				}
				switch ((*itr)->GetObjType())
				{
				case basic_info::objtype::bSubject: 
					SET_TEXT_SUCCESS(); 
					if (hasReadStudent)
					{
						++stuSubNum; 
						std::cout << "�ɹ�Ϊѧ��¼��γ�: " << (*itr)->GetID() << "�ĳɼ�" << std::endl; 
					}
					else
					{
						++subNum; 
						std::cout << "�ɹ�¼��γ�: " << (*itr)->GetID() << std::endl; 
					}
					SET_TEXT_NORMAL();
					break; 
				case basic_info::objtype::bClass:
					++clsNum; 
					SET_TEXT_SUCCESS(); 
					std::cout << "�ɹ�¼��༶: " << (*itr)->GetID() << std::endl; 
					SET_TEXT_NORMAL(); 
					break; 
				case basic_info::objtype::bStudent: 
					(*itr)->GetID(); 
					++stuNum; 
					SET_TEXT_SUCCESS();
					std::cout << "�ɹ�¼��ѧ��: " << (*itr)->GetID() << std::endl;
					SET_TEXT_NORMAL(); 
					break; 
				}
			}
			SET_TEXT_SUCCESS(); 
			std::cout << "�ɹ�¼��: ѧ��" << subNum << "��, �༶" << clsNum << "��, ѧ��" << stuNum << "��, ѧ����ϰ�γ�" << stuSubNum << "��" << std::endl; 
			std::cout << "��" << subNum + clsNum + stuNum + stuSubNum << "��" << std::endl; 
			SET_TEXT_WARNING(); 
			std::cout << "ʧ��" << errNum << "��" << std::endl; 
			SET_TEXT_NORMAL(); 
			break; 
		}
		case 'L': case 'l': 
		{
			std::string fileName; 
			std::cout << "��������Ҫ������ļ�����: " << std::flush; 
			std::getline(std::cin, fileName); 
			if (!ChangeInfo::SaveToFile(fileName))
			{
				SET_TEXT_WARNING(); std::cout << "�����ļ�ʧ�ܣ��޷����ļ�: " << fileName << std::endl; SET_TEXT_NORMAL(); 
			}
			else
			{
				SET_TEXT_SUCCESS(); std::cout << "�ɹ������ļ�" << fileName << std::endl; SET_TEXT_NORMAL();
			}
			break; 
		}
		case 'M': case 'm': 
			SET_TEXT_WARNING(); 
			std::cout << "����������ݽ��޷��ָ�����ȷ��Ҫ��������?(Y/n): " << std::flush; 
			SET_TEXT_NORMAL();
			buf = 0; 
			while (true)
			{
				std::cin >> buf; 
				std::cin.clear(); 
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
				switch (buf)
				{
				case 'Y': case 'y':
					ChangeInfo::Clear(); 
					SET_TEXT_SUCCESS(); std::cout << "������������ݣ�" << std::flush; SET_TEXT_NORMAL();
					break; 
				case 'N': case 'n': 
					SET_TEXT_SUCCESS(); std::cout << "�ѳɹ�ȡ����ղ�����" << std::flush; SET_TEXT_NORMAL(); 
					break; 
				default: 
					SET_TEXT_WARNING();
					std::cout << "����Ƿ�������������ݽ��޷��ָ�����ȷ��Ҫ��������?(Y/n): " << std::flush;
					SET_TEXT_NORMAL(); 
					continue; 
				}
				break; 
			}
			break; 
		default: 
			std::cout << "�޴�ѡ�" << std::endl; 
		}
	}
}

void UI::CompulsorySystem()

{
	system("cls");
	while (true)
	{
		std::cout << "��ǰ��ѧ���ɼ�����ϵͳѧ��ģʽ" << std::endl;
		std::cout << "A.������һ��\nB.��ʾ��ǰ������ѧ��\nC.�������ѧ���ɼ�\nD.���ĳѧ��ѧ���ɼ�\nE.���ĳ�༶ѧ���ɼ�\nF.������а༶\nG.���\nH.����\nI.����ѧ���ɼ�\nJ.ɾ��\nK.��ȡ�浵���������ǰ�ɼ��⣩\nL.����...\nM.�����������" << std::endl;
		char buf = 0;
		std::cin >> buf;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		switch (buf)
		{
		case 'A': case'a':
			SET_TEXT_WARNING();
			std::cout << "������һ����ʹ����ȫ����ʧ�������ȷ�����������Ѿ����棬��ȷ��Ҫ������? (Y/n): " << std::flush;
			buf = 0;
			while (true)
			{
				std::cin >> buf;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				switch (buf)
				{
				case 'Y': case 'y': case 'N': case 'n':
					break;
				default:
					std::cout << "����Ƿ�! ������һ����ʹ������ȫ����ʧ����ȷ����? (Y/n): " << std::flush;
					continue;
				}
				break;
			}
			SET_TEXT_NORMAL();
			if (buf == 'Y' || buf == 'y')
			{
				ChangeInfo::Clear();
				return;
			}
			break;
		case 'B': case 'b':
			PrintSubject();
			break;
		case 'C': case'c':
			std::cout << "�Ƿ񰴳ɼ�����?(Y/n)" << std::flush;
			while (true)
			{
				buf = 0;
				std::cin >> buf;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				if (buf == 'Y' || buf == 'y') { PrintStudent(true); break; }
				else if (buf == 'N' || buf == 'n') { PrintStudent(false); break; }
				else
				{
					SET_TEXT_WARNING(); std::cout << "����Ƿ����Ƿ񰴳ɼ�����?(Y/n)" << std::flush; SET_TEXT_NORMAL();
				}
			}
			break;
		case 'D': case 'd':
		{
			basic_info::idType subjectID;
			std::cout << "�������ѧ�Ƶ�ID: " << std::flush;
			while (!(std::cin >> subjectID))
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				SET_TEXT_WARNING();
				std::cout << "����Ƿ��������������ѧ�Ƶ�ID: " << std::flush;
				SET_TEXT_NORMAL();
			}
			std::cout << "�Ƿ񰴳ɼ�����?(Y/n)" << std::flush;
			while (true)
			{
				buf = 0;
				std::cin >> buf;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				if (buf == 'Y' || buf == 'y') { PrintSubjectStudent(subjectID, true); break; }
				else if (buf == 'N' || buf == 'n') { PrintSubjectStudent(subjectID, false); break; }
				else
				{
					SET_TEXT_WARNING(); std::cout << "����Ƿ����Ƿ񰴳ɼ�����?(Y/n)" << std::flush; SET_TEXT_NORMAL();
				}
			}
			break;
		}
		case 'E': case 'e':
		{
			basic_info::idType classID;
			std::cout << "������ð༶��ID: " << std::flush;
			while (!(std::cin >> classID))
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				SET_TEXT_WARNING();
				std::cout << "����Ƿ������������룡" << std::endl;
				SET_TEXT_NORMAL();
			}
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "�Ƿ񰴳ɼ�����?(Y/n)" << std::flush;
			while (true)
			{
				buf = 0;
				std::cin >> buf;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				if (buf == 'Y' || buf == 'y') { PrintClassStudent(classID, true); break; }
				else if (buf == 'N' || buf == 'n') { PrintClassStudent(classID, false); break; }
				else
				{
					SET_TEXT_WARNING(); std::cout << "����Ƿ����Ƿ񰴳ɼ�����?(Y/n)" << std::flush; SET_TEXT_NORMAL();
				}
			}
			break;
		}
		case 'F': case 'f': 
		{
			PrintClass();
			break;
		}
		case 'G': case 'g':
		{
			std::cout << "��ѡ��: A.������һ��\tB.�����ѧ��\tC.����°༶\tD.�����ѧ��" << std::endl;
			while (true)
			{
				buf = 0;
				std::cin >> buf;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				switch (buf)
				{
				case 'A': case 'a':
					break;
				case 'B': case 'b':
				{
				addNewSubject:
					basic_info::idType id;
					basic_info::scoreType fullScore;
					std::string name;
					std::cout << "��������ӵ���ѧ�Ƶ�ID: " << std::flush;
					while (!(std::cin >> id) || info.GetSubjectList().find(id) != info.GetSubjectList().end())
					{
						SET_TEXT_WARNING();
						if (std::cin) std::cout << "�˰༶ID�Ѿ���ռ�ã���������ӵ���ѧ�Ƶ�ID: " << std::flush;
						else std::cout << "����Ƿ�����������ӵ���ѧ�Ƶ�ID: " << std::flush;
						SET_TEXT_NORMAL();
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

					}
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "��������ӵ���ѧ�Ƶ�����: " << std::flush;
					std::getline(std::cin, name);
					std::cout << "��ֱ�������ӵ���ѧ�Ƶ�������: " << std::endl;
					while (!(std::cin >> fullScore))
					{
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						SET_TEXT_WARNING();
						std::cout << "����Ƿ�����ֱ�������ӵ���ѧ�Ƶ�������: " << std::endl;
						SET_TEXT_NORMAL();
					}
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					if (ChangeInfo::InsertSubject(id, name, fullScore, 1))
					{
						SET_TEXT_SUCCESS();
						std::cout << "�����ѧ�Ƴɹ���" << std::endl;
						SET_TEXT_NORMAL(); 
						if (!info.GetStudentList().empty())				//ѧ����Ϊ��
						{
							std::cout << "�Ƿ�Ϊ��ǰ����ѧ����ӳɼ�(������ӣ���ǰ����ѧ���ĳɼ�Ĭ��Ϊ��)?(Y/n): " << std::flush;
							buf = 0;
							while (true)
							{
								std::cin >> buf;
								std::cin.clear();
								std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
								switch (buf)
								{
								case 'Y': case 'y':					//¼��ɼ�
								{
									basic_info::scoreType score; 
									for (std::map<basic_info::idType, Student*>::const_iterator itr = info.GetStudentList().begin();
										itr != info.GetStudentList().end(); ++itr)
									{
										std::cout << "������ѧ��: " << itr->first << ' ' << itr->second->GetName() << " �ĳɼ�: " << std::flush; 
										while (!(std::cin >> score))
										{
											SET_TEXT_WARNING(); 
											std::cout << "����Ƿ�������������ѧ��: " << itr->first << ' ' << itr->second->GetName() << " �ĳɼ�: " << std::flush; 
											SET_TEXT_NORMAL();
											std::cin.clear();
											std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
										}
										std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
										ChangeInfo::AddStudentSubject(itr->first, id, score); 
										SET_TEXT_SUCCESS(); 
										std::cout << "�ɹ���ѧ��: " << itr->first << ' ' << itr->second->GetName() << " �ĳɼ���Ϊ: " << std::setprecision(2) << score << std::endl; 
										SET_TEXT_NORMAL();
									}
									break;
								}
								case 'N': case 'n':
								{
									for (std::map<basic_info::idType, Student*>::const_iterator itr = info.GetStudentList().begin();
										itr != info.GetStudentList().end(); ++itr)
										ChangeInfo::AddStudentSubject(itr->first, id, 0);
									SET_TEXT_SUCCESS(); std::cout << "�Ѱ�����ѧ���ɼ�����" << std::endl; SET_TEXT_NORMAL();
									break;
								}
								default:
									SET_TEXT_WARNING();
									std::cout << "����Ƿ���\n�Ƿ�Ϊ��ǰ����ѧ����ӳɼ�(������ӣ���ǰ����ѧ���ĳɼ�Ĭ��Ϊ��)?(Y/n): " << std::flush;
									SET_TEXT_NORMAL();
									continue;
								}
								break;
							}
						}
					}
					else
					{
						SET_TEXT_WARNING();
						std::cout << "���ʧ�ܣ�δ֪����" << std::endl;
						SET_TEXT_NORMAL();
					}
					std::cout << "�Ƿ�������ѧ��?(Y/n): " << std::flush;
					buf = 0;
					std::cin >> buf;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
					if (buf == 'Y' || buf == 'y') goto addNewSubject;
					break;
				}
				case 'C': case'c':
				{
				addNewClass:
					basic_info::idType id;
					std::string name;
					std::cout << "��������ӵ��°༶��ID: " << std::flush;
					while (!(std::cin >> id) || info.GetClassList().find(id) != info.GetClassList().end())
					{
						SET_TEXT_WARNING();
						if (std::cin)
							std::cout << "�˰༶ID�Ѿ���ռ�ã���������ӵ��°༶��ID: " << std::flush;
						else std::cout << "����Ƿ�����������ӵ��°༶��ID: " << std::flush;
						SET_TEXT_NORMAL();
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "��������ӵ��°༶������: " << std::flush;
					std::getline(std::cin, name);
					if (ChangeInfo::InsertClass(id, name))
					{
						SET_TEXT_SUCCESS(); std::cout << "����°༶�ɹ���" << std::endl; SET_TEXT_NORMAL();
					}
					else
					{
						SET_TEXT_WARNING(); std::cout << "���ʧ�ܣ�δ֪����" << std::endl; SET_TEXT_NORMAL();
					}
					std::cout << "�Ƿ�������?(Y/n): " << std::flush;
					buf = 0;
					std::cin >> buf;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					if (buf == 'Y' || buf == 'y') goto addNewClass;
					break;
				}
				case 'D': case'd':
				{
				addNewStudent:
					basic_info::idType id, classID;
					std::string name;
					Student::genderType gender = Student::genderType::male;
					std::cout << "��������ӵ���ѧ����ID: " << std::flush;
					while (!(std::cin >> id) || info.GetStudentList().find(id) != info.GetStudentList().end())
					{
						SET_TEXT_WARNING();
						if (std::cin)
							std::cout << "��ѧ��ID�Ѿ���ռ�ã���������ӵ��°༶��ID: " << std::flush;
						else std::cout << "����Ƿ�����������ӵ���ѧ����ID: " << std::flush;
						SET_TEXT_NORMAL();
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "��������ӵ���ѧ��������: " << std::flush;
					std::getline(std::cin, name);
					std::cout << "������ѧ�����Ա�(m/f: m-male, f-female): " << std::flush;
					buf = 0;
					while (true)
					{
						std::cin >> buf;
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						switch (buf)
						{
						case 'M': case'm':
							gender = Student::genderType::male;
							break;
						case 'F': case'f':
							gender = Student::genderType::female;
							break;
						default:
							SET_TEXT_WARNING();
							std::cout << "����Ƿ���������ѧ�����Ա�(m/f: m-male, f-female): " << std::flush;
							SET_TEXT_NORMAL();
							continue;
						}
						break;
					};
					std::cout << "�������ѧ�������༶��ID: " << std::flush;
					while (!(std::cin >> classID))
					{
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
						SET_TEXT_WARNING();
						std::cout << "����Ƿ����������ѧ�������༶��ID: " << std::flush;
						SET_TEXT_NORMAL();
					}
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
					if (ChangeInfo::InsertStudent(id, name, gender, classID))
					{
						SET_TEXT_SUCCESS(); std::cout << "�����ѧ���ɹ���" << std::endl; SET_TEXT_NORMAL(); 
						std::cout << "�Ƿ�Ϊ��ѧ��¼����Ƴɼ�(����¼�룬��Ĭ�ϸ��Ƴɼ�Ϊ��)?(Y/n): " << std::flush; 
						buf = 0; 
						while (true)
						{
							std::cin >> buf; 
							std::cin.clear(); 
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
							switch (buf)
							{
							case 'Y': case 'y': 
							{
								basic_info::scoreType score; 
								for (std::map<basic_info::idType, Subject*>::const_iterator itr = info.GetSubjectList().begin();
									itr != info.GetSubjectList().end(); ++itr)
								{
									std::cout << "�������ͬѧ��ѧ��: " << itr->first << ' ' << itr->second->GetName() << " ����ȡ�õĳɼ�: " << std::flush; 
									while (!(std::cin >> score))
									{
										SET_TEXT_WARNING();
										std::cout << "����Ƿ��������������ͬѧ��ѧ��: " << itr->first << ' ' << itr->second->GetName() << " ����ȡ�õĳɼ�: " << std::flush; 
										SET_TEXT_NORMAL();
										std::cin.clear();
										std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
									}
									std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
									ChangeInfo::AddStudentSubject(id, itr->first, score); 
									SET_TEXT_SUCCESS(); std::cout << "�ɹ�¼���ѧ�Ƴɼ���" << std::endl; SET_TEXT_NORMAL(); 
								}
								break; 
							}
							case 'N': case 'n': 
							{
								for (std::map<basic_info::idType, Subject*>::const_iterator itr = info.GetSubjectList().begin();
									itr != info.GetSubjectList().end(); ++itr)
									ChangeInfo::AddStudentSubject(id, itr->first, 0); 
								SET_TEXT_SUCCESS(); std::cout << "�ѽ���ͬѧ�����гɼ���Ϊ�㣡" << std::endl; SET_TEXT_NORMAL();
								break; 
							}
							default: 
								SET_TEXT_WARNING(); 
								std::cout << "����Ƿ����Ƿ�Ϊ��ѧ��¼����Ƴɼ�(����¼�룬��Ĭ�ϸ��Ƴɼ�Ϊ��)?(Y/n): " << std::flush; 
								SET_TEXT_NORMAL();
								continue; 
							}
							break; 
						}
					}
					else
					{
						SET_TEXT_WARNING(); std::cout << "���ʧ�ܣ������ڴ˰༶��" << std::endl; SET_TEXT_NORMAL();
					}
					std::cout << "�Ƿ�������?(Y/n): " << std::flush;
					buf = 0;
					std::cin >> buf;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					if (buf == 'Y' || buf == 'y') goto addNewStudent;
					break;
				}
				default:
					SET_TEXT_WARNING();
					std::cout << "����Ƿ���" << std::endl;
					SET_TEXT_NORMAL();
					continue;
				}
				break;
			}
			break;
		}
		case 'H': case 'h':
		{
			std::cout << "��ѡ��: A.������һ��\tB.����ѧ����Ϣ\tC.���İ༶��Ϣ\tD.����ѧ����Ϣ" << std::endl;
			buf = 0;
			std::cin >> buf;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			switch (buf)
			{
			case 'A': case 'a':
				break;
			case 'B': case 'b':
				std::cout << "��ѡ��A.����ѧ��ID\tB.����ѧ������\tC.�޸�ѧ������\tD.ȡ��" << std::endl;
				buf = 0;
				std::cin >> buf;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				switch (buf)
				{
				case 'A': case 'a':
				{
					basic_info::idType srcID, newID;
					std::cout << "����������ѧ��ԭID����ID: " << std::endl;
					while (!(std::cin >> srcID >> newID))
					{
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						SET_TEXT_WARNING();
						std::cout << "����Ƿ�������������ѧ��ԭID����ID: " << std::endl;
						SET_TEXT_NORMAL();
					}
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					switch (ChangeInfo::ChangeSubjectID(srcID, newID))
					{
					case ChangeInfo::operr::success:
						SET_TEXT_SUCCESS();
						std::cout << "�޸ĳɹ���" << std::endl;
						SET_TEXT_NORMAL();
						break;
					case ChangeInfo::operr::no_subject:
						SET_TEXT_WARNING();
						std::cout << "��ѧ�Ʋ����ڣ�" << std::endl;
						SET_TEXT_NORMAL();
						break;
					case ChangeInfo::operr::subject_exist:
						SET_TEXT_WARNING();
						std::cout << "��ID�ѱ�ռ�ã��޸�ʧ�ܣ�" << std::endl;
						SET_TEXT_NORMAL();
						break;
					}
					break;
				}
				case 'B': case 'b':
				{
					basic_info::idType id;
					std::string name;
					std::cout << "������Ҫ�޸����Ƶ�ѧ��ID: " << std::flush;
					while (!(std::cin >> id) || info.GetSubjectList().find(id) == info.GetSubjectList().end())
					{
						SET_TEXT_WARNING();
						if (std::cin) std::cout << "��ѧ�Ʋ����ڣ�����������Ҫ�޸����Ƶ�ѧ��ID: " << std::flush;
						else std::cout << "����Ƿ�������������Ҫ�޸����Ƶ�ѧ��ID: " << std::flush;
						SET_TEXT_NORMAL();
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "�������µ�ѧ������: " << std::flush;
					std::getline(std::cin, name);
					info.GetSubjectList().at(id)->SetName(name);
					break;
				}
				case 'C': case 'c':
				{
					basic_info::idType id;
					basic_info::scoreType fullScore;
					std::cout << "����������Ҫ�޸����Ƶ�ѧ��ID������: " << std::endl;
					while (!(std::cin >> id >> fullScore) || info.GetSubjectList().find(id) == info.GetSubjectList().end())
					{
						SET_TEXT_WARNING();
						if (std::cin) std::cout << "û�и�ID�Ŀγ̣�����������Ҫ�޸����Ƶ�ѧ��ID������: " << std::flush;
						else std::cout << "����Ƿ�������������Ҫ�޸����Ƶ�ѧ��ID������: " << std::flush;
						SET_TEXT_NORMAL();
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					info.GetSubjectList().at(id)->SetFullScore(fullScore);
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					break;
				}
				default:
					SET_TEXT_WARNING();
					std::cout << "����Ƿ���" << std::endl;
					SET_TEXT_NORMAL();
				case 'D': case 'd':
					break;
				}
				break;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			case 'C': case 'c':
				std::cout << "��ѡ��A.���İ༶ID\tB.���İ༶����\tC.ȡ��" << std::endl;
				buf = 0;
				std::cin >> buf;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				switch (buf)
				{
				case 'A': case 'a':
				{
					basic_info::idType srcID, newID;
					std::cout << "����������༶ԭID����ID: " << std::endl;
					while (!(std::cin >> srcID >> newID))
					{
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						SET_TEXT_WARNING();
						std::cout << "����Ƿ����޸�ʧ�ܣ�" << std::endl;
						SET_TEXT_NORMAL();
					}
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					switch (ChangeInfo::ChangeClassID(srcID, newID))
					{
					case ChangeInfo::operr::success:
						SET_TEXT_SUCCESS();
						std::cout << "�޸ĳɹ���" << std::endl;
						SET_TEXT_NORMAL();
						break;
					case ChangeInfo::operr::no_class:
						SET_TEXT_WARNING();
						std::cout << "�ð༶�����ڣ�" << std::endl;
						SET_TEXT_NORMAL();
						break;
					case ChangeInfo::operr::class_exist:
						SET_TEXT_WARNING();
						std::cout << "��ID�ѱ�ռ�ã��޸�ʧ�ܣ�" << std::endl;
						SET_TEXT_NORMAL();
						break;
					}
					break;
				}
				case 'B': case 'b':
				{
					basic_info::idType id;
					std::string name;
					std::cout << "������Ҫ�޸����Ƶİ༶ID: " << std::flush;
					while (!(std::cin >> id) || info.GetClassList().find(id) == info.GetClassList().end())
					{
						SET_TEXT_WARNING();
						if (std::cin) std::cout << "�ð༶�����ڣ�����������Ҫ�޸����Ƶİ༶ID: " << std::flush;
						else std::cout << "����Ƿ�������������Ҫ�޸����Ƶİ༶ID: " << std::flush;
						SET_TEXT_NORMAL();
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "�������µİ༶����: " << std::flush;
					std::getline(std::cin, name);
					info.GetClassList().at(id)->SetName(name);
					break;
				}
				default:
					SET_TEXT_WARNING();
					std::cout << "����Ƿ���" << std::endl;
					SET_TEXT_NORMAL();
				case 'C': case 'c':
					break;
				}
				break;
			case 'D': case 'd':
				std::cout << "��ѡ��A.����ѧ��ID\tB.����ѧ������\tC.����ѧ���Ա�\tD.����ѧ���༶\tE.����ѧ������\tF.ȡ��" << std::endl;
				buf = 0;
				std::cin >> buf;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				switch (buf)
				{
				case 'A': case 'a':
				{
					basic_info::idType srcID, newID;
					std::cout << "����������ѧ��ԭID����ID: " << std::endl;
					while (!(std::cin >> srcID >> newID))
					{
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						SET_TEXT_WARNING();
						std::cout << "����Ƿ����޸�ʧ�ܣ�" << std::endl;
						SET_TEXT_NORMAL();
					}
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					switch (ChangeInfo::ChangeStudentID(srcID, newID))
					{
					case ChangeInfo::operr::success:
						SET_TEXT_SUCCESS();
						std::cout << "�޸ĳɹ���" << std::endl;
						SET_TEXT_NORMAL();
						break;
					case ChangeInfo::operr::no_student:
						SET_TEXT_WARNING();
						std::cout << "��ѧ�������ڣ�" << std::endl;
						SET_TEXT_NORMAL();
						break;
					case ChangeInfo::operr::student_exist:
						SET_TEXT_WARNING();
						std::cout << "��ID�ѱ�ռ�ã��޸�ʧ�ܣ�" << std::endl;
						SET_TEXT_NORMAL();
						break;
					}
					break;
				}
				case 'B': case 'b':
				{
					basic_info::idType id;
					std::string name;
					std::cout << "��������Ҫ����������ѧ��ID: " << std::flush;
					while (!(std::cin >> id) || info.GetStudentList().find(id) == info.GetStudentList().end())
					{
						SET_TEXT_WARNING();
						if (std::cin) std::cout << "��ѧ�������ڣ�������������Ҫ����������ѧ��ID: " << std::endl;
						else std::cout << "����Ƿ���������������Ҫ����������ѧ��ID: " << std::endl;
						SET_TEXT_NORMAL();
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					std::cout << "������ѧ����������: " << std::flush;
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::getline(std::cin, name);
					info.GetStudentList().at(id)->SetName(name);
					SET_TEXT_SUCCESS();
					std::cout << "����ѧ�������ɹ���" << std::endl;
					SET_TEXT_NORMAL();
					break;
				}
				case 'C': case 'c':
				{
					basic_info::idType id;
					std::cout << "������Ҫ�����Ա��ѧ��ID: " << std::flush;
					while (!(std::cin >> id) || info.GetStudentList().find(id) == info.GetStudentList().end())
					{
						SET_TEXT_WARNING();
						if (std::cin) std::cout << "����Ƿ�������������Ҫ�����Ա��ѧ��ID: " << std::flush;
						else std::cout << "��ѧ�������ڣ�����������Ҫ�����Ա��ѧ��ID: " << std::flush;
						SET_TEXT_NORMAL();
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "��ǰѧ������: " << info.GetStudentList().at(id)->GetName() << ", ѧ���Ա�: "
						<< (info.GetStudentList().at(id)->GetGender() == Student::genderType::male ? "��" : "Ů") << std::endl;
					std::cout << "��ȷ��Ҫ����ѧ���Ա���? (Y/n): " << std::flush;
					buf = 0;
					while (true)
					{
						std::cin >> buf;
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						switch (buf)
						{
						case 'Y': case 'y':
							info.GetStudentList().at(id)->ReverseGender();
							SET_TEXT_SUCCESS();
							std::cout << "�޸��Ա�ɹ���" << std::endl;
							SET_TEXT_NORMAL();
							break;
						case 'N': case 'n':
							SET_TEXT_SUCCESS();
							std::cout << "��ȡ�����Ա��޸�" << std::endl;
							SET_TEXT_NORMAL();
							break;
						default:
							SET_TEXT_WARNING();
							std::cout << "����Ƿ�����ȷ��Ҫ����ѧ���Ա���? (Y/n): " << std::flush;
							SET_TEXT_NORMAL();
							continue;
						}
						break;
					}
					break;
				}
				case 'D': case 'd':
				{
					basic_info::idType studentID, classID;
					std::cout << "����������ѧ��ID���°༶��ID: " << std::endl;
					while (!(std::cin >> studentID >> classID))
					{
						SET_TEXT_WARNING();
						std::cout << "����Ƿ�������������ѧ��ID���°༶��ID: " << std::endl;
						SET_TEXT_NORMAL();
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					switch (ChangeInfo::ChangeStudentClass(studentID, classID))
					{
					case ChangeInfo::operr::success:
						SET_TEXT_SUCCESS();
						std::cout << "�޸ĳɹ���" << std::endl;
						SET_TEXT_NORMAL();
						break;
					case ChangeInfo::operr::no_student:
						SET_TEXT_WARNING();
						std::cout << "�޸�ʧ�ܣ���ѧ�������ڣ�" << std::endl;
						SET_TEXT_NORMAL();
						break;
					case ChangeInfo::operr::no_class:
						SET_TEXT_WARNING();
						std::cout << "�޸�ʧ�ܣ��°༶�����ڣ�" << std::endl;
						SET_TEXT_NORMAL();
						break;
					}
					break;
				}
				case 'E': case 'e':
				{
					basic_info::idType studentID, subjectID;
					basic_info::scoreType newScore;
					std::cout << "����������ѧ��ID��Ҫ���ĵ�ѧ��ID�Լ��µķ���: " << std::endl;
					while (!(std::cin >> studentID >> subjectID >> newScore))
					{
						SET_TEXT_WARNING();
						std::cout << "����Ƿ�������������ѧ��ID��Ҫ���ĵ�ѧ��ID�Լ��µķ���: " << std::endl;
						SET_TEXT_NORMAL();
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					switch (ChangeInfo::ChangeStudentScore(studentID, subjectID, newScore))
					{
					case ChangeInfo::operr::success:
						SET_TEXT_SUCCESS();
						std::cout << "�޸ĳɹ���" << std::endl;
						SET_TEXT_NORMAL();
						break;
					case ChangeInfo::operr::no_student:
						SET_TEXT_WARNING();
						std::cout << "�޸�ʧ�ܣ���ѧ�������ڣ�" << std::endl;
						SET_TEXT_NORMAL();
						break;
					case ChangeInfo::operr::no_subject:
						SET_TEXT_WARNING();
						std::cout << "�޸�ʧ�ܣ���ѧ��û������ѧ�Ƶĳɼ���" << std::endl;
						SET_TEXT_NORMAL();
						break;
					}
					break;
				}
				default:
					SET_TEXT_WARNING();
					std::cout << "����Ƿ���" << std::endl;
					SET_TEXT_NORMAL();
				case 'F': case 'f':
					break;
				}
				break;
			default:
				SET_TEXT_WARNING();
				std::cout << "����Ƿ���" << std::endl;
				SET_TEXT_NORMAL();
			}
			break;
		}
		case 'I': case 'i':
		{
			std::cout << "��ѡ��: A.������һ��\tB.����ID����\tC.������������" << std::endl;
			buf = 0;
			while (true)
			{
				std::cin >> buf;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				switch (buf)
				{
				case 'A': case 'a':
					break;
				case 'B': case 'b':
				{
					basic_info::idType studentID;
					std::cout << "��������Ҫ���ҵ�ѧ��ID: " << std::flush;
					while (!(std::cin >> studentID))
					{
						SET_TEXT_WARNING();
						std::cout << "����Ƿ�����������Ҫ���ҵ�ѧ��ID: " << std::flush;
						SET_TEXT_NORMAL();
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					std::map<basic_info::idType, Student*>::const_iterator itr = info.GetStudentList().find(studentID);
					if (itr == info.GetStudentList().end())
					{
						SET_TEXT_WARNING();
						std::cout << "��Ҫ�ҵ�ѧ��������" << std::endl;
						SET_TEXT_NORMAL();
					}
					else
					{
						PrintStudentInfoHead(false);
						PrintStudentInfo(info.GetStudentList().at(studentID), 0);
					}
					break;
				}
				case 'C': case 'c':
				{
					std::string name;
					bool exist = false;
					std::cout << "��������Ҫ���ҵ�ѧ������: " << std::flush;
					std::getline(std::cin, name);
					for (std::map<basic_info::idType, Student*>::const_iterator itr = info.GetStudentList().begin();
						itr != info.GetStudentList().end(); ++itr)
					{
						if (itr->second->GetName() == name)
						{
							if (!exist)
							{
								PrintStudentInfoHead(false);
								exist = true;
							}
							PrintStudentInfo(itr->second, 0);
						}
					}
					if (!exist)
					{
						SET_TEXT_WARNING();
						std::cout << "��Ҫ�ҵ�ѧ��������" << std::endl;
						SET_TEXT_NORMAL();
					}
					break;
				}
				default:
					SET_TEXT_WARNING();
					std::cout << "����Ƿ�����ѡ��: A.������һ��\tB.����ID����\tC.������������" << std::endl;
					SET_TEXT_NORMAL();
					continue;
				}
				break;
			}
			break;
		}
		case 'J': case 'j':
		{
			std::cout << "��ѡ��: A.������һ��\tB.ɾ��ѧ��\tC.ɾ���༶\tD.ɾ��ѧ��" << std::endl;
			buf = 0;
			while (true)
			{
				std::cin >> buf;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				switch (buf)
				{
				case 'A': case 'a':
					break;
				case 'B': case 'b':
				{
				delSubject:
					basic_info::idType id;
					std::cout << "��������Ҫɾ����ѧ��ID: " << std::flush;
					while (!(std::cin >> id))
					{
						SET_TEXT_WARNING();
						std::cout << "����Ƿ���������������Ҫɾ����ѧ��ID: " << std::flush;
						SET_TEXT_NORMAL();
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					SET_TEXT_WARNING();
					std::cout << "������������ɾ�����ѧ����ص�������Ϣ������ѧ���ĳɼ�����ȷ��Ҫ��������?(Y/n): " << std::flush;
					SET_TEXT_NORMAL();
					buf = 0;
					while (true)
					{
						std::cin >> buf;
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						switch (buf)
						{
						case 'Y': case 'y':
							if (ChangeInfo::DeleteSubject(id))
							{
								SET_TEXT_SUCCESS(); std::cout << "�ɹ�ɾ��ѧ��: " << id << std::endl; SET_TEXT_NORMAL();
							}
							else
							{
								SET_TEXT_WARNING(); std::cout << "ɾ��ʧ�ܣ���ѧ�Ʋ����ڣ�" << std::endl; SET_TEXT_NORMAL();
							}
							break;
						case 'N': case 'n':
							SET_TEXT_SUCCESS();
							std::cout << "��ȡ��ɾ��������" << std::endl;
							SET_TEXT_NORMAL();
							break;
						default:
							SET_TEXT_WARNING();
							std::cout << "����Ƿ���\nɾ����ѧ�ƻ�ɾ�����ѧ����ص�������Ϣ������ѧ���ĳɼ�����ȷ��Ҫ��������?(Y/n): " << std::flush;
							SET_TEXT_NORMAL();
							continue;
						}
						break;
					}
					std::cout << "�Ƿ����ɾ��ѧ��?(Y/n)" << std::endl;
					buf = 0;
					std::cin >> buf;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					if (buf == 'Y' || buf == 'y') goto delSubject;
					break;
				}
				case 'C': case 'c':
				{
				delClass:
					basic_info::idType id;
					std::cout << "��������Ҫɾ���İ༶ID: " << std::flush;
					while (!(std::cin >> id))
					{
						SET_TEXT_WARNING();
						std::cout << "����Ƿ���������������Ҫɾ���İ༶ID: " << std::flush;
						SET_TEXT_NORMAL();
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					SET_TEXT_WARNING();
					std::cout << "�ò������ɻָ�����ȷ��Ҫɾ���ð༶��?(Y/n): " << std::flush;
					SET_TEXT_NORMAL();
					buf = 0;
					while (true)
					{
						std::cin >> buf;
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						switch (buf)
						{
						case 'Y': case 'y':
							switch (ChangeInfo::DeleteClass(id))
							{
							case ChangeInfo::operr::success:
								SET_TEXT_SUCCESS();
								std::cout << "�ɹ�ɾ���༶: " << id << std::endl;
								SET_TEXT_NORMAL();
								break;
							case ChangeInfo::operr::no_class:
								SET_TEXT_WARNING();
								std::cout << "ɾ��ʧ�ܣ��ð༶�����ڣ�" << std::endl;
								SET_TEXT_NORMAL();
								break;
							case ChangeInfo::operr::student_exist:
								SET_TEXT_WARNING();
								std::cout << "ɾ��ʧ�ܣ��ð༶����ѧ����ɾ��ǰ���Ƚ��༶��գ�" << std::endl;
								SET_TEXT_NORMAL();
								break;
							}
							break;
						case 'N': case 'n':
							SET_TEXT_SUCCESS();
							std::cout << "��ȡ��ɾ��������" << std::endl;
							SET_TEXT_NORMAL();
							break;
						default:
							SET_TEXT_WARNING();
							std::cout << "����Ƿ���\nɾ���ð༶���ɻָ�����ȷ��Ҫɾ���ð༶��?(Y/n): " << std::flush;
							SET_TEXT_NORMAL();
							continue;
						}
						break;
					}
					std::cout << "�Ƿ����ɾ���༶?(Y/n)" << std::endl;
					buf = 0;
					std::cin >> buf;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					if (buf == 'Y' || buf == 'y') goto delClass;
					break;
				}
				case 'D': case 'd':
				{
				delStudent:
					basic_info::idType id;
					std::cout << "��������Ҫɾ����ѧ��ID: " << std::flush;
					while (!(std::cin >> id))
					{
						SET_TEXT_WARNING();
						std::cout << "����Ƿ���������������Ҫɾ����ѧ��ID: " << std::flush;
						SET_TEXT_NORMAL();
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					SET_TEXT_WARNING();
					std::cout << "������������ɾ����ѧ����������Ϣ����ȷ��Ҫ��������?(Y/n): " << std::flush;
					SET_TEXT_NORMAL();
					buf = 0;
					while (true)
					{
						std::cin >> buf;
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						switch (buf)
						{
						case 'Y': case 'y':
							if (ChangeInfo::DeleteStudent(id))
							{
								SET_TEXT_SUCCESS(); std::cout << "�ɹ�ɾ��ѧ��: " << id << std::endl; SET_TEXT_NORMAL();
							}
							else
							{
								SET_TEXT_WARNING(); std::cout << "ɾ��ʧ�ܣ���ѧ�������ڣ�" << std::endl; SET_TEXT_NORMAL();
							}
							break;
						case 'N': case 'n':
							SET_TEXT_SUCCESS();
							std::cout << "��ȡ��ɾ��������" << std::endl;
							SET_TEXT_NORMAL();
							break;
						default:
							SET_TEXT_WARNING();
							std::cout << "����Ƿ���\nɾ����ѧ��������ɾ����ѧ����������Ϣ����ȷ��Ҫ��������?(Y/n): " << std::flush;
							SET_TEXT_NORMAL();
							continue;
						}
						break;
					}
					std::cout << "�Ƿ����ɾ��ѧ��?(Y/n)" << std::endl;
					buf = 0;
					std::cin >> buf;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					if (buf == 'Y' || buf == 'y') goto delStudent;
					break;
				}
				default:
					SET_TEXT_WARNING();
					std::cout << "����Ƿ�����ѡ��: A.������һ��\tB.ɾ��ѧ��\tC.ɾ���༶\tD.ɾ��ѧ��" << std::endl;
					SET_TEXT_NORMAL();
					continue;
				}
				break;
			}
			break;
		}
		case 'K': case 'k':
		{
			std::string fileName;
			std::cout << "������Ҫ��ȡ���ļ�����" << std::endl;
			std::getline(std::cin, fileName);
			bool hasReadStudent = false;			//��¼�Ƿ�¼����ѧ��
			std::list<basic_info*> readInfo;
			std::cout << "��ʼ�������ݣ���ȴ�..." << std::endl;
			readInfo = ChangeInfo::ReadFromFile(fileName);
			size_t subNum = 0, clsNum = 0, stuNum = 0, stuSubNum = 0, errNum = 0;
			for (std::list<basic_info*>::const_iterator itr = readInfo.begin();
				itr != readInfo.end(); ++itr)
			{
				if (!(*itr))						//�������
				{
					++errNum;
					SET_TEXT_WARNING();
					std::cout << "�ö���������" << std::endl;
					SET_TEXT_NORMAL();
					continue;
				}
				else if (*itr == (basic_info*)(-1))	//��ʼ����ѧ��
				{
					hasReadStudent = true;
					continue;
				}
				switch ((*itr)->GetObjType())
				{
				case basic_info::objtype::bSubject:
					SET_TEXT_SUCCESS();
					if (hasReadStudent)
					{
						++stuSubNum;
						std::cout << "�ɹ�Ϊѧ��¼��γ�: " << (*itr)->GetID() << "�ĳɼ�" << std::endl;
					}
					else
					{
						++subNum;
						std::cout << "�ɹ�¼��γ�: " << (*itr)->GetID() << std::endl;
					}
					SET_TEXT_NORMAL();
					break;
				case basic_info::objtype::bClass:
					++clsNum;
					SET_TEXT_SUCCESS();
					std::cout << "�ɹ�¼��༶: " << (*itr)->GetID() << std::endl;
					SET_TEXT_NORMAL();
					break;
				case basic_info::objtype::bStudent:
					(*itr)->GetID();
					++stuNum;
					SET_TEXT_SUCCESS();
					std::cout << "�ɹ�¼��ѧ��: " << (*itr)->GetID() << std::endl;
					SET_TEXT_NORMAL();
					break;
				}
			}
			SET_TEXT_SUCCESS();
			std::cout << "�ɹ�¼��: ѧ��" << subNum << "��, �༶" << clsNum << "��, ѧ��" << stuNum << "��, ѧ����ϰ�γ�" << stuSubNum << "��" << std::endl;
			std::cout << "��" << subNum + clsNum + stuNum + stuSubNum << "��" << std::endl;
			SET_TEXT_WARNING();
			std::cout << "ʧ��" << errNum << "��" << std::endl;
			SET_TEXT_NORMAL();
			break;
		}
		case 'L': case 'l':
		{
			std::string fileName;
			std::cout << "��������Ҫ������ļ�����: " << std::flush;
			std::getline(std::cin, fileName);
			if (!ChangeInfo::SaveToFile(fileName))
			{
				SET_TEXT_WARNING(); std::cout << "�����ļ�ʧ�ܣ��޷����ļ�: " << fileName << std::endl; SET_TEXT_NORMAL();
			}
			else
			{
				SET_TEXT_SUCCESS(); std::cout << "�ɹ������ļ�" << fileName << std::endl; SET_TEXT_NORMAL();
			}
			break;
		}
		case 'M': case 'm':
			SET_TEXT_WARNING();
			std::cout << "����������ݽ��޷��ָ�����ȷ��Ҫ��������?(Y/n): " << std::flush;
			SET_TEXT_NORMAL();
			buf = 0;
			while (true)
			{
				std::cin >> buf;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				switch (buf)
				{
				case 'Y': case 'y':
					ChangeInfo::Clear();
					SET_TEXT_SUCCESS(); std::cout << "������������ݣ�" << std::flush; SET_TEXT_NORMAL();
					break;
				case 'N': case 'n':
					SET_TEXT_SUCCESS(); std::cout << "�ѳɹ�ȡ����ղ�����" << std::flush; SET_TEXT_NORMAL();
					break;
				default:
					SET_TEXT_WARNING();
					std::cout << "����Ƿ�������������ݽ��޷��ָ�����ȷ��Ҫ��������?(Y/n): " << std::flush;
					SET_TEXT_NORMAL();
					continue;
				}
				break;
			}
			break;
		default:
			std::cout << "�޴�ѡ�" << std::endl;
		}
	}
}

void UI::PrintSubject()
{
	if (mode == modeType::optional)
	{
		std::cout << std::endl << "ѧ���嵥\n" << separator << std::endl;
		std::cout << std::setw(idLength) << "�γ�ID|" << std::setw(nameLength) << "�γ�����|"
			<< std::setw(scoreLength) << "����|" << std::setw(5) << "ѧ��" << std::endl;
		for (std::map<basic_info::idType, Subject*>::const_iterator itr = info.GetSubjectList().begin();
			itr != info.GetSubjectList().end(); ++itr)
		{
			std::cout << std::setw(idLength) << itr->first << std::setw(nameLength) << itr->second->GetName() << std::setw(scoreLength) << std::setprecision(2)
				<< itr->second->GetFullScore() << std::setw(5) << std::setprecision(2) << itr->second->GetCredit() << std::endl;
		}
		std::cout << separator << std::endl << std::endl;
	}
	else
	{
		std::cout << "ѧ���嵥\n" << separator << std::endl; 
		std::cout << std::setw(idLength) << "�γ�ID|" << std::setw(nameLength) << "�γ�����|"
			<< std::setw(scoreLength) << "����" << std::endl; 
		for (std::map<basic_info::idType, Subject*>::const_iterator itr = info.GetSubjectList().begin();
			itr != info.GetSubjectList().end(); ++itr)
		{
			std::cout << std::setw(idLength) << itr->first << std::setw(nameLength) << itr->second->GetName() << std::setw(scoreLength) << std::setprecision(2)
				<< itr->second->GetFullScore() << std::endl;
		}
		std::cout << separator << std::endl << std::endl;
	}
}

void UI::PrintStudentInfoHead(bool sortedByScore)
{

	std::cout << std::setw(idLength) << "ѧ��ID|" << std::setw(nameLength) << "����|"
		<< std::setw(5) << "�Ա�|" << std::setw(idLength) << "�༶ID|" << std::setw(scoreLength) << (mode == modeType::optional ? "����|" : "�ܷ�");
	if (sortedByScore) std::cout << std::setw(5) << "����";
	std::cout << std::endl;
	std::cout << std::setw(idLength) << "�γ�ID|" << std::setw(nameLength) << "�γ�����|" << std::setw(scoreLength) << "����"; 
	if (mode == modeType::optional) std::cout << std::setw(5) << "ѧ��"; 
	std::cout << std::endl;
	std::cout << starSeparator << std::endl;

}

void UI::PrintStudentInfo(Student* pStudent, size_t sortedByScore)
{
	std::cout << std::setw(idLength) << pStudent->GetID() << std::setw(nameLength) << pStudent->GetName()
		<< std::setw(5) << ((pStudent->GetGender() == Student::genderType::male) ? "��" : "Ů")
		<< std::setw(idLength) << pStudent->GetClassID() << std::setw(scoreLength) << std::setprecision(2) << pStudent->GetValid();
	if (sortedByScore) std::cout << std::setw(5) << sortedByScore;
	for (std::map<basic_info::idType, basic_info::scoreType>::const_iterator itr = pStudent->GetSubjectList().begin();
		itr != pStudent->GetSubjectList().end(); ++itr)
	{
		std::cout << std::endl << thinSeparator << std::endl;
		std::cout << std::setw(idLength) << itr->first << std::setw(nameLength) << info.GetSubjectList().at(itr->first)->GetName()
			<< std::setw(scoreLength) << std::setprecision(2) << itr->second; 
		if (mode == modeType::optional) std::cout << std::setw(5) << info.GetSubjectList().at(itr->first)->GetCredit(); 
	}
	std::cout << std::endl << starSeparator << std::endl;
}

void UI::PrintStudent(bool sortedByScore)
{
	std::cout << std::endl << "ѧ���ɼ���\n" << separator << std::endl;
	PrintStudentInfoHead(sortedByScore); 
	std::multimap<basic_info::scoreType, Student*, std::greater<basic_info::scoreType>> sortStudent;
	size_t count = 0;				//��¼����
	if (sortedByScore)
	{

		//����
		for (std::map<basic_info::idType, Student*>::const_iterator itr = info.GetStudentList().begin();
			itr != info.GetStudentList().end(); ++itr)
		{
			sortStudent.insert(std::pair<basic_info::scoreType, Student*>(itr->second->GetValid(), itr->second));
		}

		//���
		for (std::multimap<basic_info::scoreType, Student*>::const_iterator itr = sortStudent.begin();
			itr != sortStudent.end(); ++itr)
		{
			PrintStudentInfo(itr->second, ++count);
		}
	}
	else
	{
		for (std::map<basic_info::idType, Student*>::const_iterator itr = info.GetStudentList().begin();
			itr != info.GetStudentList().end(); ++itr)
		{
			PrintStudentInfo(itr->second, 0);
		}
	}
	std::cout << "ѧ������: " << info.GetStudentList().size() << std::endl;
	std::cout << separator << std::endl << std::endl;
}

void UI::PrintSubjectStudent(basic_info::idType subjectID, bool sortedByScore)
{
	if (info.GetSubjectList().find(subjectID) == info.GetSubjectList().end())
	{
		std::cout << std::endl << "������IDΪ" << subjectID << "�Ŀγ̣�" << std::endl << std::endl; 
		return; 
	}
	std::cout << std::endl << "ѧ���ɼ���\tѧ��ID: " << subjectID << "\tѧ������: " << info.GetSubjectList().at(subjectID)->GetName()
		<< "\t����: " << info.GetSubjectList().at(subjectID)->GetFullScore();
	if(mode == modeType::optional) std::cout << "\tѧ��: " << info.GetSubjectList().at(subjectID)->GetCredit();
	std::cout << std::endl << separator << std::endl; 
	if (sortedByScore)
	{
		std::multimap<basic_info::scoreType, Student*, std::greater<basic_info::scoreType> > sortStudent; 
		size_t count = 0;	//��¼����

		//����
		for (std::map<basic_info::idType, basic_info::scoreType>::const_iterator itr = info.GetSubjectList().at(subjectID)->GetStudentList().begin();
			itr != info.GetSubjectList().at(subjectID)->GetStudentList().end(); ++itr)
		{
			sortStudent.insert(std::make_pair(itr->second, info.GetStudentList().at(itr->first))); 
		}

		//���
		std::cout << std::setw(idLength) << "ѧ��ID|" << std::setw(nameLength) << "����|"
			<< std::setw(5) << "�Ա�|" << std::setw(idLength) << "�༶ID|" << std::setw(scoreLength) << "�ɼ�|" << std::setw(5) << "����" << std::endl;
		for (std::multimap<basic_info::scoreType, Student*>::iterator itr = sortStudent.begin();
			itr != sortStudent.end(); ++itr)
		{
			std::cout << std::setw(idLength) << itr->second->GetID() << std::setw(nameLength) << itr->second->GetName()
				<< std::setw(5) << itr->second->GetGender() << std::setw(idLength) << itr->second->GetClassID() 
				<< std::setw(scoreLength) << std::setprecision(2) << itr->first << std::setw(5) << ++count << std::endl;
		}
	}
	else
	{
		std::cout << std::setw(idLength) << "ѧ��ID|" << std::setw(nameLength) << "����|"
			<< std::setw(5) << "�Ա�|" << std::setw(idLength) << "�༶ID|" << std::setw(scoreLength) << "�ɼ�" << std::endl;
		for (std::map<basic_info::idType, basic_info::scoreType>::const_iterator itr = info.GetSubjectList().at(subjectID)->GetStudentList().begin();
			itr != info.GetSubjectList().at(subjectID)->GetStudentList().end(); ++itr)
		{
			std::cout << std::setw(idLength) << itr->first << std::setw(nameLength) << info.GetStudentList().at(itr->first)->GetName()
				<< std::setw(5) << info.GetStudentList().at(itr->first)->GetGender() << std::setw(idLength)
				<< info.GetStudentList().at(itr->first)->GetClassID() << std::setw(scoreLength) << std::setprecision(2) << itr->second << std::endl;
		}
	}
	std::cout << "ƽ���ɼ�: " << info.GetSubjectList().at(subjectID)->GetAverage() << std::endl; 
	std::cout << separator << std::endl << std::endl; 
}

void UI::PrintClassStudent(basic_info::idType classID, bool sortedByScore)
{
	if (info.GetClassList().find(classID) == info.GetClassList().end())
	{
		std::cout << std::endl << "������IDΪ" << classID << "�İ༶��" << std::endl << std::endl;
		return;
	}
	std::cout << std::endl << "ѧ���ɼ���\t�༶ID: " << classID << "\t�༶����: " << info.GetClassList().at(classID)->GetName();
	std::cout << std::endl << separator << std::endl;
	PrintStudentInfoHead(sortedByScore); 
	if (sortedByScore)
	{
		std::multimap<basic_info::scoreType, Student*, std::greater<basic_info::scoreType> > sortStudent;
		size_t count = 0;	//��¼����

		//����
		for (std::set<basic_info::idType>::const_iterator itr = info.GetClassList().at(classID)->GetStudentList().begin();
			itr != info.GetClassList().at(classID)->GetStudentList().end(); ++itr)
		{
			sortStudent.insert(std::make_pair(info.GetStudentList().at(*itr)->GetValid(), info.GetStudentList().at(*itr)));
		}

		//���
		for (std::multimap<basic_info::scoreType, Student*>::iterator itr = sortStudent.begin();
			itr != sortStudent.end(); ++itr)
		{
			PrintStudentInfo(itr->second, ++count);
		}
	}
	else
	{
		for (std::set<basic_info::idType>::const_iterator itr = info.GetClassList().at(classID)->GetStudentList().begin();
			itr != info.GetClassList().at(classID)->GetStudentList().end(); ++itr)
		{
			PrintStudentInfo(info.GetStudentList().at(*itr), 0);
		}
	}
	std::cout << "ƽ���ɼ�: " << info.GetClassList().at(classID)->GetAverage() << std::endl;
	std::cout << separator << std::endl << std::endl;
}

void UI::PrintClass()
{
	std::cout << std::endl << "�༶����" << std::endl << separator << std::endl; 
	std::cout << std::setw(idLength) << "�༶ID" << std::setw(nameLength) << "�༶����" << std::setw(scoreLength) << "����" << std::endl;
	for (std::map<basic_info::idType, Class*>::const_iterator itr = info.GetClassList().begin();
		itr != info.GetClassList().end(); ++itr)
	{
		std::cout << std::setw(idLength) << itr->first << std::setw(nameLength) << itr->second->GetName()
			<< std::setw(scoreLength) << std::setprecision(2) << itr->second->GetAverage() << std::endl;
	}
	std::cout << separator << std::endl << std::endl; 
}
