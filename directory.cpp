//------------- directory.cpp -------------
// Definitions for class Directory

#include <iostream>
#include <cstring>
#include "directory.h"


Directory::Directory()
// Constructor Created
// Setup Empty directory of entires 
{
	maxSize = 5;
	currentSize = 0;
	entryList = new Entry[maxSize];
}

Directory::~Directory()
// 
// 
{
	delete[] entryList;
}

void Directory::insert()
// 
{
	if (currentSize == maxSize)			// 
		Grow();
	entryList[currentSize++].Load();	// Read new Entry
}
void Directory::Lookuo() const
// 
{
	// 
	char aName[20];
	std::cout << "\tType the name to be looked up, followed by <Enter>: ";
	std::cin.getline(aName, 20);

	int thisEntry = FindName(aName);	// 

	if (thisEntry == -1)
		std::cout << aName << "not found in current directory\n";
	else
	{
		std::cout << "\n Entry found: ";
		entryList[thisEntry].Show();	// 
	}
}

void Directory::Remove()
// 
{
	// 
	char aName[20];
	std::cout << "\nType name to be removed, followed by <Enter>: ";
	std::cin.getline(aName, 20);

	int thisEntry = FindName(aName);	// 

	int(thisEntry == -1)
		std::cout << aName << "not found in directory";
	else
	{
		//
		//
		for (int j = thisEntry + 1; j < currentSize; j++)
			entryList[j - 1] = entryList[j];
		currentSize--;					// 
		std::cout << "Entry Removed\n";
	}
}

void Directory::Update()
//
//
{
	std::cout << "\n Please enter the name of the entry to be modified: ";

}