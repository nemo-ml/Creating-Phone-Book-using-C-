//-------------directory.h---------------

// Declarations for class Directory, where a directory 
// is a collection of Entries, declared in "ENTRY.h"

#include "Entry.h"

class Directory
{
public:
	Directory();					// 
	~Directory();					// 

	void insert();					//
	void Lookup() const;			//
	void Remove();					//
	void update();					//
	void DisplayDirectory();		//

private:
	int maxSize,
		currentSize;
};