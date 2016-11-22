#pragma once
#include "Sorting.h"
#include <chrono>
#include <random>
#include "point.h"
#include "Line.h"

//Usings for chrono timetaker package
using std::chrono::time_point;
using Clock = std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::milliseconds;

int main()
{
	
#pragma region 7.53
	//7.53
    cout << "------------------------------------" << endl;
    cout << "------------- Task 7.53 ------------" << endl;
    cout << "------------------------------------" << endl;

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
	cout << "Task A) - O(N^2) algorithm. " << endl;
	int k = rd() % 20000;

	//starting clock
	time_point<Clock> start;
	time_point<Clock> end;
	milliseconds diff;

    cout << "Running function 10 times for comparesion purposes" << endl;

	bool resultQuad;
	for (int i = 0; i<10; i++)
	{
		start = Clock::now();
		
		resultQuad = s753.quadraticSort(k);
		
		// Stop Clock
		end = Clock::now();
		diff = duration_cast<milliseconds>(end - start);

		cout << "Function took: " << diff.count() << "ms" << endl;
		
	//Results
	if (resultQuad)
		cout << "match found" << endl;
	else
		cout << "match not found" << endl;
	
    }

	//b)
	cout << endl << "Task B) - O(N log N) Algorithm" << endl;
	//sorting first
	//cout << "current list:" << endl;
	//s753.print();

	s753.sort();
	//cout << "sorted list:" << endl;
	//s753.print();


	//LinearSearch
    cout << "Running function 10 times for comparesion purposes" << endl;
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

	if (foundit)
		cout << "Match found in samples" << endl;
	else
		cout << "No match found in samples" << endl;

	}

#pragma endregion All functions of assignment 7.53

#pragma region 7.44

    //7.44
    cout << "------------------------------------" << endl;
    cout << "------------- Task 7.44 ------------" << endl;
    cout << "------------------------------------" << endl;

    vector<int> samples2;
    for (int i = 0; i<200; i++)
    {
        if ((rd() % 50000) > 25000)
            samples2.push_back(1);
        else
            samples2.push_back(0);
    }

    Sorting s744(samples2);

    //print list
    s744.print();

    s744.sortNFalseBeforeTrue();

    s744.print();

#pragma endregion


#pragma region 7.38

    //7.38
    cout << "------------------------------------" << endl;
    cout << "------------- Task 7.38 ------------" << endl;
    cout << "------------------------------------" << endl;

    vector<Point> samples3;
    for (int i = 0; i<300; i++)
    {
        int x = rd() % 200;
        int y = rd() % 200;
        Point newP(x, y);
        samples3.push_back(newP);
    }

    Sorting s738(samples3);

    vector<Line> lines = s738.findLinesBySortAndSlope();

    cout << "found " << lines.size() << " lines with 4 or more points" << endl;

#pragma endregion

	system("pause");
    
}