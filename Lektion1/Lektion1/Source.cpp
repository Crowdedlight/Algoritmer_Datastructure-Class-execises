
#include <iostream>
#include "Recursion.h"
using namespace std;

int main()
{
	int input;

	Recursion obj = Recursion("MyRecursions");

	while(true)
	{
		cout << "input n, must be larger than 0" << endl;
		cin >> input;
		cout << "Sum = " << obj.SumOfNatural(input) << endl << endl;
	}


}