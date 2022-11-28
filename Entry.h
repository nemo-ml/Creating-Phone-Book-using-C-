#pragma once
//--------------------------- Entry.h --------------------------

// Declarations for Class Entry for a Phone Directory

// A C++ program consists of various entities such as variables, functions, types, and namespaces.
// Each of these entities must be declared before they can be used.
// A declaration specifies a unique name for the entity, along with information about its type and other characteristics.
// In C++ the point at which a name is declared is the point at which it becomes visible to the compiler. 
// You can't refer to a function or class that is declared at some later point in the compilation unit. 
// Variables should be declared as close as possible before the point at which they're used



class Entry
{
public:

// Class members declared as public can be used by any function. When preceding a list of class members, 
// the public keyword specifies that those members are accessible from any function.
// This applies to all members declared up to the next access specifier or the end of the class


	Entry();						//	Constructor. Initializes all Values to blank

	// Constructor in C++ is a special method that is invoked automatically at the time of object creation. 
	// It is used to initialize the data members of new objects generally.
	// The constructor in C++ has the same name as the class or structure.
	// Constructor is invoked at the time of object creation.
	// It constructs the values i.e. provides data for the object which is why it is known as constructors. 
	// Constructor does not have a return value, hence they do not have a return type


	void Load();					//	Load the Data in an Entry 

	// Void functions are known as Non-Value Returning functions. They are “void” due 
	// to the fact that they are not supposed to return values. True, but not completely.
	// We cannot return values but there is something we can surely return from void functions. 
	// Void functions do not have a return type, but they can do return values


	void Show() const;				//	Display an Entry to the Screen
	const char* GetName() const;	//	Return Name in an Entry

	// The first occurence of the const keyword in the above statement is in the data 
	// type of the return value of the function GetName(), which is also a constant function
	// This means that the value returned by GetName() will be:
	//		# of type char
	//		# a pointer
	//		# a const value
	// Since the return value will be const, GetName() will recieve a pointer to a constant char value

private:

// Class members declared as private can be used only by member functions and friends (classes or functions) of the class
// When preceding a list of class members, the private keyword specifies that those members are accessible only from 
// member functions and friends of the class. This applies to all members declared up to the next access specifier or
// the end of the class


	char name[20];					// chracter array of size 20
	char phoneNumber[20];			// Set for all three 
	char address[20];
};
