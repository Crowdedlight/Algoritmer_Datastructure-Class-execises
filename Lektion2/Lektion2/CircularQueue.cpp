#include "CircularQueue.h"



CircularQueue::CircularQueue(int size)
{
	queue = new int[size];
	top = 0;
	end = 0;
	this->size = size;
}

void CircularQueue::Enqueue(int i)
{
	if (end == size-1 && top != 0)
	{
		//Need to jump to beginning
		queue[end] = i;
		end = 0;
	}
	else if (end+1 != top)
	{
		//add element
		queue[end++] = i;
	}
	else
	{
		//end would overtake top
		cout << "ERROR: END WOULD OVERTAKE TOPS PLACE" << endl;
	}
}

int CircularQueue::Dequeue()
{
	//remove element from head
	if (top == end)
	{
		cout << "ERROR: QUEUE IS EMPTY" << endl;
		return -1;
	}

	int temp = queue[top];

	if (top == size-1)
	{
		//jump to 0
		top = 0;			
	}
	else
	{
		//normal dequeue
		top++;
	}

	return temp;
}


void CircularQueue::print()
{
	for (int i = top; i != end;)
	{
		cout << queue[i] << ", ";

		//next element
		i = (i + 1) % size;
	}

	cout << endl;
}



CircularQueue::~CircularQueue()
{
	delete[] queue;
}
