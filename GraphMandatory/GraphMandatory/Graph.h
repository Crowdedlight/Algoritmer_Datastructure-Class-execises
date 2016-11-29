#pragma once
#include "Vertex.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Graph
{
public:
    Graph(string name);
	void addVertex(string data);
	void addVertex(Vertex v);
	void addEdge(string from, string to, int weight);
	void print();
    ~Graph();

private:
    vector<Vertex> graphContainer;
	string name;
};

