//------------ menu.cpp --------------
//	Main Function 
//	Test Program and General Support Functions
//	for phone Directory.

#include <cctype>							//
#include <iostream>							//
#include "directory.h"						//


void ShowMenu()
//
{
	std::cout << "\n\t\t***Menu Phone Directory***";
	std::cout << "\n\tI \tInsert a new Entry into directory";
	std::cout << "\n\tL \tLook up an Entry";
	std::cout << "\n\tR \tRemove an Entry";
	std::cout << "\n\tU \tUpdate an Entry";
	std::cout << "\n\tD \tDisplay the entire Directory";
	std::cout << "\n\t? \tDisplay this menu";
	std::cout << "\n\tQ \tQuite";
}

char GetAChar(const char* promptString)
//
//
{
	char response;							//
    std::cout << promptString;
	std::cin >> response;					//
	response = toupper(response);			//
	std::cin.get();							//
	return response;
}

bool Legal(char c)
//
//
//

{
	return ((c == 'I') || (c == 'L')|| (c =='') || (c == 'R') || (c == 'U') || (c == '?') || (c == 'Q'));		
}

char GetCommand()
//
//
//
{
	char cmd = GetAChar("\n\n>");				//

	while (!Legal(cmd))							//
	{											//
		std::cout << "\nIllegal command, please try again . . .";
		ShowMenu();
		cmd = GetAChar("\n\n>");
	}
	return cmd;
}

int main()
{
	Directory d;								//
	
	ShowMenu();									//

	char command;								//
	do
	{
		command = GetCommand();					//
		switch (command)
		{
		case 'I': d.insert(); break;
		case 'L': d.Lookup(); break;
		case 'R': d.Remove(); break;
		case 'U': d.update(); break;
		case 'D': d.DisplayDirectory(); break;
		case '?': ShowMenu(); break;
		case 'Q': '\0'; break;
		}
	} while (command != 'Q');

	return 0;
}