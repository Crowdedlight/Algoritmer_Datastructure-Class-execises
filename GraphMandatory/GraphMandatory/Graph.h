#pragma once
#include "Vertex.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

#define INFINITY 5000000

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
    void dijkstra(string s);
    void printShortestPath(string target);
    int getVertexByData(string data);
    ~Graph();

private:
    vector<Vertex> sortSmallestFirst(vector<Vertex> items);
    int smallestUnknownVertex();
    bool unknownDistVertex();
    vector<Vertex> graphContainer;
	string name;
};

struct smallestTopNum {
    bool operator()( Vertex& fP, Vertex& sP) const {
        return fP.getTopNum() < sP.getTopNum();
    }
};

