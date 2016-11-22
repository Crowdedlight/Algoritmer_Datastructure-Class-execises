#include "Line.h"



Line::Line()
{
}

void Line::addPoint(Point p)
{
    points.push_back(p);
}

int Line::getSize()
{
    return points.size();
}

void Line::clear()
{
    points.clear();
}

Line::~Line()
{
}
