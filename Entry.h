#pragma once
//-------------------- Entry.h -------------------

// Declarations for Class Entry for a Phone Directory

class Entry
{
public:
	Entry();						//	Initializes all Values to blank
	void Load();					//	Load the Data in an Entry 
	void Show() const;				//	Display an Entry to the Screen
	const char* GetName() const;	//	Return Name in an Entry

private:
	char name[20];					// chracter array of size 20
	char phoneNumber[20];
	char address[20];
};
