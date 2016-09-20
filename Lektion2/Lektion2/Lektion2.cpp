#include "Lektion2.h"
#include <stack>
#include <queue>
using namespace std;

Lektion2::Lektion2()
{
}

bool Lektion2::balPar(string txt )
{
	
	stack<int> parentesis;

	for (int i = 0; i < txt.length(); i++)
	{
		if (txt[i] == '(')
		{
			parentesis.push(i);
		}
		else if (txt[i] == ')')
		{
			if (parentesis.empty())
				return false;
			
			parentesis.pop();
		}
	}
	if (parentesis.empty())
		return true;
	return false;
}






Lektion2::~Lektion2()
{
}
