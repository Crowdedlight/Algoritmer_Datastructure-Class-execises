#pragma once
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Sorting
{
public:
	Sorting(vector<int> sample);

	bool quadraticSort(int k);
	void sort();
	void print();
	bool linearSearch(int k);

	~Sorting();

private:
	vector<int> samples;

};

