#include "ui.h"

int main()
{
	std::cout << std::setiosflags(std::ios::fixed); 
	UI::StartProcedure(); 
	UI ui; 
	while (true) if (!ui.Run()) break;		//ѭ������
	UI::EndProcedure(); 
	return 0; 
}

