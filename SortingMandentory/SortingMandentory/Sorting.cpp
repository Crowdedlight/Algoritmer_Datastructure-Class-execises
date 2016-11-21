#include "Sorting.h"



Sorting::Sorting(vector<int> sample)
{
	samples = sample;
}

bool Sorting::quadraticSort(int k)
{

	for (auto i : samples)
	{
		for (auto j : samples)
		{
			if (i + j == k)
			{
				return true;
			}
		}
	}
	
	return false;
}

void Sorting::sort()
{
	make_heap(samples.begin(), samples.end());
	sort_heap(samples.begin(), samples.end());
}

void Sorting::print()
{
	for (auto i : samples)
	{
		cout << i << ",";
	}
	cout << endl;
}

bool Sorting::linearSearch(int k)
{
	int front = 0;
	int back = samples.size() - 1;

	bool match = false;

	while(!match)
	{
		static int sum;
		sum = samples[front] + samples[back];

		if (front == back && sum != k)
			break;
		
		if (sum < k)
			front++;
		else if (sum > k)
			back--;
		else if (sum == k)
			return true;
	}
}





Sorting::~Sorting()
{
}
