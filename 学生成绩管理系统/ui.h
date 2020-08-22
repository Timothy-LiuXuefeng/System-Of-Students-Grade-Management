#ifndef UI_H

#define UI_H

///////////////////////////////////////////
//
//  UI����
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <windows.h>
#include "info.h"


//ȡ��windows.h�ж����max��
#ifdef max
#undef max
#endif

//����̨��ɫ
#define BLACK_COLOR 0
#define DARKBLUE_COLOR 1
#define GREEN_COLOR 2
#define LIGHTBLUE_COLOR 3
#define RED_COLOR 4
#define PERPLE_COLOR 5
#define YELLO_COLOR 6
#define LIGHTGRAY_COLOR 7
#define GRAY_COLOR 8
#define BLUE_COLOR 9
#define LIGHTGREEN_COLOR A
#define LIGHTLIGHTBLUE_COLOR B
#define LIGHTRED_COLOR C
#define LIGHTPURPLE_COLOR D
#define LIGHTYELLO_COLOR E
#define WHITE_COLOR F

#define _BLACK_COLOR 0x0
#define _DARKBLUE_COLOR 0x1
#define _GREEN_COLOR 0x2
#define _LIGHTBLUE_COLOR 0x3
#define _RED_COLOR 0x4
#define _PERPLE_COLOR 0x5
#define _YELLO_COLOR 0x6
#define _LIGHTGRAY_COLOR 0x7
#define _GRAY_COLOR 0x8
#define _BLUE_COLOR 0x9
#define _LIGHTGREEN_COLOR 0xA
#define _LIGHTLIGHTBLUE_COLOR 0xB
#define _LIGHTRED_COLOR 0xC
#define _LIGHTPURPLE_COLOR 0xD
#define _LIGHTYELLO_COLOR 0xE
#define _WHITE_COLOR 0xF

//������������̨��ɫ

#define CONSOLE_COLOR_STR(bk, text) "color "#bk#text							//����ѹ�����滻ָ���ַ���
#define SET_CONSOLE_COLOR(bk, text) system(CONSOLE_COLOR_STR(bk, text))			//���ÿ���̨��ɫ
#define SET_CONSOLE_MAIN_COLOR() SET_CONSOLE_COLOR(BLACK_COLOR, WHITE_COLOR)	//Ĭ����ɫ

//���ý����������������ɫ

#define SET_TEXT_WARNING() SetConsoleTextAttribute(hConsoleOutPut, (_BLACK_COLOR << (sizeof(WORD) * 4)) + _RED_COLOR)	//������ɫ
#define SET_TEXT_NORMAL() SetConsoleTextAttribute(hConsoleOutPut, (_BLACK_COLOR << (sizeof(WORD) * 4)) + _WHITE_COLOR)	//������ɫ
#define SET_TEXT_SUCCESS() SetConsoleTextAttribute(hConsoleOutPut, (_BLACK_COLOR << (sizeof(WORD) * 4)) + _GREEN_COLOR)	//�ɹ���ɫ


static const std::string about("���ƣ�ѧ���ɼ�����ϵͳ\n�汾��v1.0\n���ߣ���ѩ��\nCopyRight (C) 2020 �����������ƻ���(2) ��������Ȩ��"); 
static const std::string separator("=========================================================================================="); 
static const std::string halfSeparator("=============================================");
static const std::string thinSeparator("------------------------------------------------------------------------------------------");
static const std::string starSeparator("******************************************************************************************");


extern HANDLE hConsoleOutPut; 

class UI							//��¼�й�UI�ĺ���
{
public: 

	//���캯��
	UI() : nameLength(25), idLength(15), scoreLength(8) {}

	static void StartProcedure(); 
	static void EndProcedure(); 
	bool Run();					//��ʼ����

private: 

	bool ChooseMode();			//ѡ��ģʽ
	void OptionalSystem();		//ѡ��ģʽ
	void CompulsorySystem();	//����ģʽ

	//��ӡ
	void PrintSubject(); 
	void PrintStudent(bool sortedByScore);
	void PrintSubjectStudent(basic_info::idType subjectID, bool sortedByScore);
	void PrintClassStudent(basic_info::idType classID, bool sortedByScore);
	void PrintClass(); 
	void PrintStudentInfoHead(bool sortedByScore); 
	void PrintStudentInfo(Student* pStudent, size_t sortedByScore); 

	//����
	void OptionalAdd();					//ѡ��ģʽ���
	void OptionalChange();				//ѡ��ģʽ����
	void OptionalSearch();				//ѡ��ģʽ����
	void OptionalDelete();				//ѡ��ģʽɾ��
	void OptionalRead();				//ѡ��ģʽ��ȡ�浵

	void CompulsoryAdd();				//����ģʽ���
	void CompulsoryChange();			//����ģʽ����
	void CompulsorySearch();			//����ģʽ����
	void CompulsoryDelete();			//����ģʽɾ��
	void CompulsoryRead();				//����ģʽ��ȡ�浵

	std::streamsize nameLength;			//���ֳ���
	std::streamsize idLength;			//ID����
	std::streamsize scoreLength;		//��������

	Info info; 
};

#endif	//#ifndef UI_H
