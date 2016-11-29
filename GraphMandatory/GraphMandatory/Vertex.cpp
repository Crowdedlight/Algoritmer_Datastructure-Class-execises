#include "Vertex.h"


Vertex::Vertex(string data)
{
    this->data = data;
}

string Vertex::getData()
{
	return data;
}

void Vertex::addEdge(Edge newE)
{
	adjVertex.push_back(newE);
}

vector<Edge> Vertex::getEdges()
{
	return adjVertex;
}




Vertex::~Vertex()
{
}
