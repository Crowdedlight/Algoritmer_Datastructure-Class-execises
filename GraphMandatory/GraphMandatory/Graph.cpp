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
    queue<int> queue;
    int counter = 0;

    for (int i = 0; i < graphContainer.size(); i++)
    {
        if (graphContainer[i].getIndegree() == 0)
            queue.push(i);
    }

    while (!queue.empty())
    {
        Vertex* v = &graphContainer[queue.front()];
        queue.pop();

        v->setTopNum(counter++);

        //decrement all vertex this points too
        for (auto adjV : v->getEdges())
        {
            graphContainer[adjV.dest].decrementIndegree();

            //if next element is indegree 0 push on queue
            if (graphContainer[adjV.dest].getIndegree() == 0)
                queue.push(adjV.dest);
        }
    }
}

vector<Vertex> Graph::sortSmallestFirst(vector<Vertex> items)
{
    make_heap(items.begin(), items.end(), smallestTopNum());
    sort_heap(items.begin(), items.end(), smallestTopNum());

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
        for (auto j : i.getEdges())
        {
            cout << "(" << graphContainer[j.dest].getData() << "," << j.weight << ")";
            cout << " ";
        }
        cout << endl;
    }
}

int Graph::getVertexByData(string data)
{
    for (int v = 0; v < graphContainer.size(); v++)
    {
        if (graphContainer[v].getData() == data)
            return v;
    }
}

void Graph::dijkstra(string vertex)
{
    //set info for each vertex
    for (int v = 0; v < graphContainer.size(); v++)
    {
        graphContainer[v].known = false;
        graphContainer[v].dist = INFINITY;
    }

    Vertex* s = &graphContainer[getVertexByData(vertex)];
    s->dist = 0;

    while (unknownDistVertex())
    {
        //find smallest edge
        int index = smallestUnknownVertex();
        Vertex* sV = &graphContainer[index];
        sV->known = true;

        for (auto edge : sV->getEdges())
        {
            Vertex* target = &graphContainer[edge.dest];
            if (!target->known)
            {
                //cost from sV to edge.dest                
                int cvw = edge.weight;

                if (sV->dist + cvw < target->dist)
                {
                    //update dist 
                    target->dist = sV->dist + cvw;
                    target->path = sV;
                }
            }
        }
    }
}

int Graph::smallestUnknownVertex()
{
    int smallest = INFINITY; //large amount for init. Has to be larger than any cost that can occur
    int cost = INFINITY;
    for (int i = 0; i < graphContainer.size(); i++)
    {
        Vertex v = graphContainer[i];
        if (!v.known && v.dist != INFINITY)
        {
            if (v.dist < cost)
            {
                cost = v.dist;
                smallest = i;
            }
        }
    }

    return smallest;
}

void Graph::printShortestPath(string vertex)
{
    Vertex target = graphContainer[getVertexByData(vertex)];
    if (target.path != nullptr)
    {
        printShortestPath(target.path->getData());
        cout << " to ";
    }
    cout << target.getData();
}

bool Graph::unknownDistVertex()
{
    for (auto i : graphContainer)
    {
        if (i.known == false)
            return true;
    }
    return false;
}

Graph::~Graph()
{
}
