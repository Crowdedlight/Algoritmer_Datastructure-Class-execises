#pragma once
#include "Vertex.h"
#include <vector>

using namespace std;

class Graph
{
public:
    Graph();
    ~Graph();

private:
    vector<Vertex> data;
};

