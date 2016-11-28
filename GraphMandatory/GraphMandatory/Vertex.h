#pragma once
#include <vector>

using namespace std;

template <class T>
class Vertex
{
public:
    Vertex(T data, int weight = 0);
    ~Vertex();

private:
     T data;
     vector<Vertex*> adjVertex;
     int weight;
};

