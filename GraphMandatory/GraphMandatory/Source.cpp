#pragma once
#include "Graph.h"
#include <iostream>

using namespace std;

int main()
{

	//Directed graf, addEdge only adds to source adjList
	Graph graf("MyGraph");

    Vertex V0("V0");

	graf.addVertex(V0);
	graf.addVertex("V1");
	graf.addVertex("V2");
	graf.addVertex("V3");
    graf.addVertex("V4");
    graf.addVertex("V5");

	graf.addEdge("V0", "V1", 3);
	graf.addEdge("V0", "V2", 5);
	graf.addEdge("V1", "V3", 5);
	graf.addEdge("V2", "V3", 1);
	graf.addEdge("V3", "V4", 4);
    graf.addEdge("V1", "V5", 5);
    graf.addEdge("V5", "V4", 1);

	graf.print();

    graf.topologicalSort();
    graf.printTopSort();

    cout << "DJIkstra:" << endl;

    graf.dijkstra("V0");
    graf.printShortestPath("V5");
    cout << endl;

    graf.printShortestPath("V4");
    cout << endl;


    system("pause");
    return 0;
}