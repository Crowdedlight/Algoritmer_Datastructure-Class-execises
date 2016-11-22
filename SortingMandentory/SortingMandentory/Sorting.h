#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include "point.h"
#include "Line.h"

using namespace std;

class Sorting
{
public:
	Sorting(vector<int> sample);
    Sorting(vector<Point> sample);
	bool quadraticSort(int k);
	void sort();
	void print();
	bool linearSearch(int k);
    void sortNFalseBeforeTrue();

    vector<Line> findLinesBySortAndSlope();
    void sortPoints();

	~Sorting();

private:
	vector<int> samples;
    vector<Point> points;
};

//Struct for compare function for sortPoints
struct greaterP {
    bool operator()(const Point& fP, const Point& sP) const {
        return fP.slope > sP.slope;
    }
};

