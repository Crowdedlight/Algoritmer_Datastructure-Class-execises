#pragma once
#include <vector>
#include "point.h"

using namespace std;

class Line
{
public:
    Line();
    void addPoint(Point p);
    int getSize();
    void clear();

    ~Line();
private:
    vector<Point> points;
};

