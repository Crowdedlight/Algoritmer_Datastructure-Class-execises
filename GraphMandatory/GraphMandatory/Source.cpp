#pragma once
#include "Graph.h"
#include <iostream>

using namespace std;

int main()
{

	//Directed graf, addEdge only adds to source adjList
	Graph graf("MyGraph");

	graf.addVertex("V0");
	graf.addVertex("V1");
	graf.addVertex("V2");
	graf.addVertex("V3");

	graf.addEdge("V0", "V1", 3);
	graf.addEdge("V0", "V2", 5);
	graf.addEdge("V1", "V3", 5);
	graf.addEdge("V2", "V3", 1);
	graf.addEdge("V3", "V1", 1);

	graf.print();

    system("pause");
    return 0;
}