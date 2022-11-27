//------------- directory.h ---------------

// Declarations for class Directory, where a directory 
// is a collection of Entries, declared in "ENTRY.h"

#include "Entry.h"

class Directory
{
public:
	Directory();							// 
	~Directory();							// 

	void insert();							//
	void Lookup() const;					//
	void Remove();							//
	void Update();							//
	void DisplayDirectory() const;			//

private:
	int maxSize, currentSize;				// 

	Entry* entryList;						// 

	void Grow();
	int FindName(char* aName) const;		// 
};