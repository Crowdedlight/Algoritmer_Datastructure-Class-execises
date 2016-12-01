#include "Vertex.h"


Vertex::Vertex(string data)
{
    this->data = data;
    this->indegree = 0;
}

string Vertex::getData()
{
	return data;
}

void Vertex::addEdge(Edge newE)
{
	adjVertex.push_back(newE);
}

void Vertex::incrementIndegree()
{
    indegree++;
}

void Vertex::decrementIndegree()
{
    indegree--;
}

bool Vertex::hasVertexAdj(int v)
{
    for (auto i : adjVertex)
    {
        if (i.dest == v)
            return true;
    }
    return false;
}

vector<Edge> Vertex::getEdges()
{
	return adjVertex;
}

int Vertex::getIndegree()
{
    return indegree;
}

void Vertex::setTopNum(int num)
{
    topNum = num;
}




Vertex::~Vertex()
{
}
