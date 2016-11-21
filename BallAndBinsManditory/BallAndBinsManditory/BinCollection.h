#pragma once
#include <vector>
#include <random>
#include <iostream>

using namespace std;
class BinCollection
{
public:
	BinCollection(int size);
	void putBalls(int amount);
	void putBallsPof2(int amount);
	void clear();

	int findLargestBin();

	~BinCollection();

private:
	int binSize;
	vector<int> bins;
	random_device rd;
	mt19937 mt;

};

