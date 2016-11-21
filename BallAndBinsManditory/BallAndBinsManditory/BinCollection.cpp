#include "BinCollection.h"



BinCollection::BinCollection(int size)
{
	this->binSize = size;
	bins.resize(size);

	//Setup random
	random_device rd;
	mt19937 mt(rd());
	this->mt = mt;
}

void BinCollection::putBalls(int amount)
{
	int maxSize = bins.size() - 1;
	uniform_int_distribution<unsigned long int> dist(0, maxSize);

	for (auto i = 0; i < amount; i++)
	{
		int rand = dist(mt);
		bins[rand]++;
	}
}

void BinCollection::putBallsPof2(int amount)
{
	int maxSize = bins.size() - 1;
	uniform_int_distribution<unsigned long int> dist(0, maxSize);

	for (auto i = 0; i < amount; i++)
	{
		int rand = dist(mt);
		int rand2 = dist(mt);

		if (bins[rand] > bins[rand2])
		{
			//Put in rand2
			bins[rand2]++;
		}
		else
		{
			//put in rand
			bins[rand]++;
		}
	}
}

int BinCollection::findLargestBin()
{
	int largestPos = -1;

	for (auto i : bins)
	{
		if (i > largestPos)
			largestPos = i;
	}

	return largestPos;
}

void BinCollection::clear()
{
	bins.clear();
	bins.resize(binSize);
}



BinCollection::~BinCollection()
{
}
