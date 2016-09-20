#include "Recursion.h"



Recursion::Recursion(string na)
{
	name = na;
}

int Recursion::SumOfNatural(int n)
{
	if (n == 1)
		return 1;
	else
		return n + SumOfNatural(n - 1);
}

bool Recursion::IsPrime(int n)
{
	if (isDivisible(n, n / 2))
		return false;
	else
		return true;	
}

bool Recursion::isDivisible(int x, int y)
{
	if (y == 1)
		return false;

	if (!(x%y))
		return true;
	else
		return isDivisible(x, y - 1);

}

Recursion::~Recursion()
{
}
