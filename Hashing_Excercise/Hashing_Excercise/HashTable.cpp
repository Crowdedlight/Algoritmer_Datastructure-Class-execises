#include "HashTable.h"



HashTable::HashTable(int size = 101)
{
	for (auto entry : table)
	{
		entry.info = EMPTY;
	}
}


HashTable::~HashTable()
{
}

int HashTable::findPos(string key)
{
	int offset = 1;
	int currentPos = myHash(key);

	while ( table[currentPos].info != EMPTY &&
		table[currentPos].key != key)
	{
		currentPos += offset; //Compute ith probe
		offset += 5;
		if (currentPos >= table.size())
			currentPos -= table.size();
	}

	return currentPos;


int HashTable::myHash(string key)
{
	int hashVal = 0;

	for (char ch : key)
	{
		hashVal = 37 * hashVal + ch;
	}

	return hashVal;
}



bool HashTable::insert(int item)
{
	
}

