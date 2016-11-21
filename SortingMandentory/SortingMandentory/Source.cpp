#pragma once
#include "Sorting.h"
#include <chrono>
#include <random>

//Usings for chrono timetaker package
using std::chrono::time_point;
using Clock = std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::milliseconds;

int main()
{
	
	//7.53
	vector<int> first = { 8, 4, 1, 6 };

	//Samples
	random_device rd;
	vector<int> samples;
	for (int i = 0; i<10000; i++)
	{
		samples.push_back(rd() % 50000);
	}

	Sorting s753(samples);

	//quadraticSort n^2
	//a)
	cout << "Task A)" << endl;
	int k = rd() % 20000;

	//starting clock
	time_point<Clock> start;
	time_point<Clock> end;
	milliseconds diff;

	bool resultQuad;
	for (int i = 0; i<10; i++)
	{
		start = Clock::now();
		
		resultQuad = s753.quadraticSort(k);
		
		// Stop Clock
		end = Clock::now();
		diff = duration_cast<milliseconds>(end - start);

		cout << "Function took: " << diff.count() << "ms" << endl;
		
	}
	//Results
	if (resultQuad)
		cout << "match found" << endl;
	else
		cout << "match not found" << endl;

	//b)
	cout << "Task B)" << endl;
	//sorting first
	cout << "current list:" << endl;
	//s753.print();

	s753.sort();
	cout << "sorted list:" << endl;
	//s753.print();

	//LinearSearch
	//starting clock
	bool foundit;
	for(int i = 0; i<10; i++)
	{		
		start = Clock::now();

		foundit = s753.linearSearch(k);

		// Stop Clock
		end = Clock::now();
		diff = duration_cast<milliseconds>(end - start);

		cout << "Function took: " << diff.count() << "ms" << endl;
	}

	if (foundit)
		cout << "Match found in samples" << endl;
	else
		cout << "No match found in samples" << endl;


	system("pause");
}