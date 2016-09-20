#pragma once

#include <string>
using namespace std;

class Recursion
{
public:
	Recursion(string name);

	int SumOfNatural(int n);
	bool IsPrime(int n);
	bool isDivisible(int x, int y);

	~Recursion();

private:
	string name;

};

