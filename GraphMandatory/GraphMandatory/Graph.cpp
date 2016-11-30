#include "Graph.h"



Graph::Graph(string name)
{
	this->name = name;
}

void Graph::addVertex(Vertex v)
{
	graphContainer.push_back(v);
}

void Graph::addVertex(string data)
{
	Vertex newV(data);
	addVertex(newV);
}

///Directed Edges. Only adds to adjList from source vertex
void Graph::addEdge(string from, string to, int weight)
{
	int source = -1, target = -1;
	//find to and from index
	for (auto i = 0; i < graphContainer.size(); i++)
	{
		if (graphContainer[i].getData() == from)
			source = i;
		if (graphContainer[i].getData() == to)
			target = i;

		if (source != -1 && target != -1)
			break;
	}

	Edge newE(target, weight);

	graphContainer[source].addEdge(newE);

}

void Graph::print()
{
	for (auto i : graphContainer)
	{
		cout << "Vertex: " << i.getData() << "    Have Edges (dest,cost): ";
		for(auto j : i.getEdges())
		{
			cout << "(" << graphContainer[j.dest].getData() << "," << j.weight << ")";
			cout << " ";
		}
		cout << endl;
	}
}




Graph::~Graph()
{
}
