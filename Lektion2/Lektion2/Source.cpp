#include "Lektion2.h"
#include "CircularQueue.h"
#include <iostream>
using namespace std;

int main()
{

	//Lektion2 lek2;

	//cout << boolalpha;

	//string test = "(ttestesre)sdfdf(dsdgsd)";
	//bool t1 = lek2.balPar(test);

	//cout << test << endl;
	//cout << t1 << endl;

	//string test2 = "()gjghj()hgff))(";
	//bool t2 = lek2.balPar(test2);

	//cout << test2 << endl;
	//cout << t2 << endl;

	CircularQueue CQ(5);

	CQ.Enqueue(1);
	CQ.print();
	CQ.Enqueue(2);
	CQ.print();
	CQ.Enqueue(3);
	CQ.print();
	CQ.Enqueue(4);
	CQ.print();

	CQ.Dequeue();
	CQ.print();
	CQ.Dequeue();
	CQ.print();



	system("pause");

	CQ.Enqueue(5);
	CQ.print();
	CQ.Enqueue(6);
	CQ.print();
	system("pause");

	return 0;
}