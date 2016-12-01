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
    graphContainer[target].incrementIndegree();

	graphContainer[source].addEdge(newE);

}

void Graph::topologicalSort()
{    
    for (int i = 0; i < graphContainer.size(); i++)
    {
        int zeroV = -1;
        //find indegree 0
        for (int j = 0; j < graphContainer.size(); j++)
        {
            if (graphContainer[j].getIndegree() == 0)
            {
                zeroV = j;
                break;
            }
        }

        //if cycles
        if (zeroV == -1)
        {
            cout << "ERROR: Cycle found." << endl;
            break;
        }

        graphContainer[zeroV].setTopNum(i);

        //each vertex that got zeroV in adj, indgree--;
        for (auto v : graphContainer)
        {
            if (v.hasVertexAdj(zeroV))
                v.decrementIndegree();
        }         
    }
}

vector<Vertex> Graph::sortSmallestFirst(vector<Vertex> items)
{
    make_heap(items.begin(), items.end(), smallestIndegree());
    sort_heap(items.begin(), items.end(), smallestIndegree());

    return items;
}

void Graph::printTopSort()
{
    vector<Vertex> temp = sortSmallestFirst(graphContainer);

    for (auto i : temp)
    {
        cout << i.getData() << ",";
    }
    cout << endl;
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