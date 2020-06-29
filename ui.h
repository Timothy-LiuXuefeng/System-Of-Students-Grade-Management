#ifndef UI_H

#define UI_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <windows.h>
#include "ChangeInfo.h"


//取消windows.h中定义的max宏
#ifdef max
#undef max
#endif

//控制台颜色
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

//设置整个控制台颜色

#define CONSOLE_COLOR_STR(bk, text) "color "#bk#text							//生成压缩呢替换指令字符串
#define SET_CONSOLE_COLOR(bk, text) system(CONSOLE_COLOR_STR(bk, text))			//设置控制台颜色
#define SET_CONSOLE_MAIN_COLOR() SET_CONSOLE_COLOR(BLACK_COLOR, WHITE_COLOR)	//默认颜色

//设置接下来输出的文字颜色

#define SET_TEXT_WARNING() SetConsoleTextAttribute(hConsoleOutPut, (_BLACK_COLOR << (sizeof(WORD) * 4)) + _RED_COLOR)	//警告颜色
#define SET_TEXT_NORMAL() SetConsoleTextAttribute(hConsoleOutPut, (_BLACK_COLOR << (sizeof(WORD) * 4)) + _WHITE_COLOR)	//正常颜色
#define SET_TEXT_SUCCESS() SetConsoleTextAttribute(hConsoleOutPut, (_BLACK_COLOR << (sizeof(WORD) * 4)) + _GREEN_COLOR)	//成功颜色


static const std::string about("名称：学生成绩管理系统\n版本：v1.0\n作者：刘雪枫\nCopyRight (C) 2020 计算机程序设计基础(2) 保留所有权利"); 
static const std::string separator("========================================"); 
static const std::string halfSeparator("====================");
static const std::string thinSeparator("----------------------------------------");
static const std::string starSeparator("****************************************");


extern HANDLE hConsoleOutPut; 

class UI							//记录有关UI的函数
{
public: 
	static void StartProcedure(); 
	static bool ChooseMode(); 
	static void CompulsorySystem(); //必修模式
	static void OptionalSystem();	//选修模式
	static void EndProcedure(); 

	static void PrintSubject(); 
	static void PrintStudent(bool sortedByScore); 
	static void PrintSubjectStudent(basic_info::idType subjectID, bool sortedByScore); 
	static void PrintClassStudent(basic_info::idType classID, bool sortedByScore);
	static void PrintClass(); 

	static std::streamsize nameLength;	//名字长度
	static std::streamsize idLength;	//ID长度
	static std::streamsize scoreLength;	//分数长度
private: 
	static void PrintStudentInfoHead(bool sortedByScore); 
	static void PrintStudentInfo(Student* pStudent, size_t sortedByScore); 
};



#endif	//#ifndef UI_H
