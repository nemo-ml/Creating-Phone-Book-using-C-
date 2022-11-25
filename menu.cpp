//------------ menu.cpp --------------
//	Main Function 
//	Test Program and General Support Functions
//	for phone Directory.

#include <cctype>							//
#include <iostream>							//
#include <directory.h>						//

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
	std::cout << "\n\t\Q \tQuite";
}

char GetAChar(const char* promptString)
//
//
{
	char response;							//
std:cout << promptString;
	cin >> response;						//
	response = toupper(response);			//
	cin.get();								//
	return response;
}

bool Legal(char c)
//
//
//

{
	return ((c == 'I') || (c == 'L' || (c == 'D) || (c == 'R') || (c == 'U') || 
}

int main()
{
	std::cout << " Building " << std::endl;
	return 0;
}