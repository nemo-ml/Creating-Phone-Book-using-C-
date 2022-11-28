//------------- directory.cpp -------------
// Definitions for class Directory

#include <iostream>
#include <cstring>						// This header file defines several functions 
										// to manipulate C strings and arrays
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

// This destructor function for class Directory
// deallocates the directory's list of Entry objects.

{
	delete[] entryList;
}

void Directory::insert()

// Insert a new entry into the direrctory.

{
	if (currentSize == maxSize)			// If the directory is full, grow it.
		Grow();
	entryList[currentSize++].Load();	// Read new Entry
}
void Directory::Lookup() const

//  Display the directory entry for a name.

{
	// Prompt the user for a name to be looked up

	char aName[20];
	std::cout << "\tType the name to be looked up, followed by <Enter>: ";
	std::cin.getline(aName, 20);

	int thisEntry = FindName(aName);	// Locate the name in the directory

	if (thisEntry == -1)
		std::cout << aName << "not found in current directory\n";
	else
	{
		std::cout << "\n Entry found: ";
		entryList[thisEntry].Show();	// display entry
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
	char aName[20];
	std::cin.getline(aName, 20);

	int thisEntry = FindName(aName);

	if (thisEntry == -1)
		std::cout << aName << "not found in the current directory\n";
	else
	{
		std::cout << "\n Current directory is: \n";
		entryList[thisEntry].Show();		//

		std::cout << "\n Replace with new Entries as follows: \n";
		entryList[thisEntry].Load();		// 		
	}
}

void Directory::DisplayDirectory() const
//
//
{
	if (currentSize == 0)
	{
		std::cout << "\n Current Direcoty is Empty \n";
		return;
	}

	// Display a Header
	std::cout << "\n\t***NAME***\t\t***PHONE***\t\t***ADDRESS***\n\n";

	for (int i = 0; i < currentSize; i++)	//
		entryList[i].Show();				//
}

void Directory::Grow()
//
//
//
{
	maxSize = currentSize + 5;				//
	Entry* newList = new Entry[maxSize];	//

	for (int i = 0; i < currentSize; i++)	//
		newList[i] = entryList[i];			//

	delete[] entryList;						//
	entryList = newList;					//
}

int Directory::FindName(char* aName) const
//
//
//
{
	for (int i = 0; i < currentSize; i++)	//
		if (strcmp(entryList[i].GetName(),
			aName) == 0)
			return i;						//
	return -1;								//
}