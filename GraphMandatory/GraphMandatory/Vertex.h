#pragma once
#include <vector>
#include <string>
using namespace std;

struct Edge
{
	int dest; //index in graph vector
	int weight; //cost 

	Edge(int dest, int weight)
	{
		this->dest = dest;
		this->weight = weight;
	}
};

class Vertex
{
public:
    Vertex(string data);
	string getData();
	void addEdge(Edge newE);
	vector<Edge> getEdges();
    ~Vertex();

private:
     string data;
	 vector<Edge> adjVertex;
};

