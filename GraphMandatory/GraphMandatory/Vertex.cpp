#include "Vertex.h"


template <class T>
Vertex::Vertex(T data, int weight = 0)
{
    this.data = data;
    this.weight = weight;
}

template <class T>
Vertex::~Vertex()
{
}
