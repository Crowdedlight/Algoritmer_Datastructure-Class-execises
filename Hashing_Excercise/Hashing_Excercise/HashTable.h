#pragma once
#include <string>
#include <vector>

using namespace std;

class HashTable
{
public:
	HashTable(int size = 101);

	bool insert(int item);

	~HashTable();

	enum entryType { ACTIVE, EMPTY, DELETED };

private:
	struct hashEntry
	{
		string key;
		int value;
		entryType info;

		hashEntry(int item, entryType type = EMPTY)
			: value {item}, info{type} {}
	};
	
	
	vector<hashEntry> table;
	int currentSize;

	int myHash(string item);
	int findPos(string key);

};

