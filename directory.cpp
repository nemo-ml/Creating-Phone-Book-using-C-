//------------- directory.cpp -------------
// Definitions for class Directory

#include <iostream>
#include <cstring>						// This header file defines several functions 
										// to manipulate C strings and arrays
#include "directory.h"


Directory::Directory()

// Constructor Created. Setup Empty directory of entires 
// Constructor in C++ is a special method that is invoked automatically at the time of object creation. 
// It is used to initialize the data members of new objects generally. 
// The constructor in C++ has the same name as the class or structure. 
// Constructor is invoked at the time of object creation. Constructor gets called automatically when
// we create the object of the class
// It constructs the values i.e. provides data for the object which is why it is known as constructors.
// Constructor does not have a return value, hence they do not have a return type
{
	maxSize = 5;
	currentSize = 0;
	entryList = new Entry[maxSize];
}

Directory::~Directory()

// This destructor function for class Directory, deallocates the directory's list of Entry objects.
// Destructor is an instance member function which is invoked automatically whenever an object is going to be destroyed. 
// Meaning, a destructor is the last function that is going to be called before an object is destroyed.
// Destructor is also a special member function like constructor.Destructor destroys the class objects created by 
// constructor. Destructor has the same name as their class name preceded by a tilde(~) symbol.

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

	std::cout << "\tType the name to be looked up, followed by <Enter> : ";
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

// Remove an entry from the directory

{
	// Prompt the user for the name to be removed

	char aName[20];

	std::cout << "\nType name to be removed, followed by <Enter>: ";
	std::cin.getline(aName, 20);

	int thisEntry = FindName(aName);	// Locate the name in the directory

	if (thisEntry == -1)
		std::cout << aName << "not found in directory";
	else
	{
		// Shift each succeding element "down" one position in the
		// Entry array, thereby deleting the desired entry

		for (int j = thisEntry + 1; j < currentSize; j++)
			entryList[j - 1] = entryList[j];

		currentSize--;					// Decrement the current number of entries
		std::cout << "Entry Removed\n";
	}
}

void Directory::Update()

// Update an existing directory entry by reentering
// each of its values (name, phone, and room number)

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
		entryList[thisEntry].Show();		// Display the current entry

		std::cout << "\n Replace with new Entries as follows: \n";
		entryList[thisEntry].Load();		// Get new values for entry		
	}
}

void Directory::DisplayDirectory() const

// Display the current directory entries
// on the standard output (the screen)

{
	if (currentSize == 0)
	{
		std::cout << "\n Current Direcoty is Empty \n";
		return;
	}

	// Display a Header
	std::cout << "\n\t***NAME***\t\t***PHONE***\t\t***ADDRESS***\n\n";

	for (int i = 0; i < currentSize; i++)	// For each entry
		entryList[i].Show();				// send it to output
}

void Directory::Grow()

// Double the size of the directory's entry list by creating a new, larger array of entries
// and changing the directory's pointer to refer to this new array

{
	maxSize = currentSize + 5;				// Determine a new size
	Entry* newList = new Entry[maxSize];	// Allocate a new array

	for (int i = 0; i < currentSize; i++)	// Copy each entry into 
		newList[i] = entryList[i];			// the new array

	delete[] entryList;						// Remove the old array
	entryList = newList;					// Point old name to new array
}

int Directory::FindName(char* aName) const

// Locate a name in the directory. Returns the position of the entry list as an integer if found.
// and returns -1 if the entry is not found in the directory

{
	for (int i = 0; i < currentSize; i++)	// Look at each entry
		if (strcmp(entryList[i].GetName(), aName) == 0)
			return i;						// If found, return position and exit

	return -1;								// Return -1 if never found
}