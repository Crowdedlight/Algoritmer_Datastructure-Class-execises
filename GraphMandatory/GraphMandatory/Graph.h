#pragma once
#include "Vertex.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Graph
{
public:
    Graph(string name);
	void addVertex(string data);
	void addVertex(Vertex v);
	void addEdge(string from, string to, int weight);
	void print();
    void printTopSort();
    void topologicalSort();
    ~Graph();

private:
    vector<Vertex> sortSmallestFirst(vector<Vertex> items);
    vector<Vertex> graphContainer;
	string name;
};

struct smallestIndegree {
    bool operator()( Vertex& fP, Vertex& sP) const {
        return fP.getIndegree() < sP.getIndegree();
    }
};

