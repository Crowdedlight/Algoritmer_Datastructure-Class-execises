#pragma once
#include <iostream>
using namespace std;
class CircularQueue
{
public:
	CircularQueue(int size);

	void Enqueue(int i);
	int Dequeue();

	void print();

	~CircularQueue();

private:
	int top;
	int end;
	int size;
	int* queue;
};

