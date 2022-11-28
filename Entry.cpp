//------------- Entry.cpp ----------------

// Definition of Class Entry for a Phone Directory

// Some entities, including functions, classes, enums, and constant variables,
// must be defined as well as declared. A definition provides the compiler with
// all the information it needs to generate machine code when the entity is used later in the program. 


#include <iostream>		// < > to look globally, " " locally 
#include <cstring>		// for strlen, strcpy_s
#include "Entry.h"		// for Class Entry


//----------------Member Function-----------------

Entry::Entry()

// This Constructor Class Entry initializes the name, phone, number,
// and room number to be blank string.

{
	strcpy_s(name, " ");
	strcpy_s(phoneNumber, " ");
	strcpy_s(address, " ");

	// The strcpy_s function copies the contents in the address of src, 
	// including the terminating null character, to the location that's specified by dest
}

void Entry::Load()

// Allow us to read in the data from the keyboard

{
	std::cout << "\nType name, followed by RETURN or Enter: ";
	std::cin.getline(name, 20);											// Gets a name; Discard newline.
	std::cout << "\nType phone number, followed ny RETURN or Enter: ";
	std::cin.getline(phoneNumber, 20);									// Gets a phone number; Discard newline.
	std::cout << "\nType address, followed by REURN or Enter: ";
	std::cin.getline(address, 20);										// Gets an address; Discard newline.
}

void Entry::Show() const
{
	int i;

	std::cout << 't' << name;				// Display name (after tabbing)
	//	Display remaining blanks, so that data lines up on screen
	for (i = strlen(name) + 1; i < 20; i++)
		std::cout.put(' ');					// Output the line of text

	std::cout << 't' << phoneNumber;		// Display Phone Number
	for (i = strlen(phoneNumber) + 1; i < 20; i++)
		std::cout.put(' ');					

	std::cout << 't' << address;			// Display Address
		std::cout << '\n';
}

const char* Entry::GetName() const			// Return the name part of an Entry
{
	return name;
}