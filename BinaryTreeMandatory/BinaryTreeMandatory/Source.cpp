#pragma once
#include "BinarySearchTree.h"
#include "AvlTree.h"
#include <iostream>
#include <chrono>

using namespace std;

//Usings for chrono timetaker package
using std::chrono::time_point;
using Clock = std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::milliseconds;

int main()
{
	
	//Make a binary search tree
	BinarySearchTree bst = BinarySearchTree();
	AvlTree avl = AvlTree();

	//Add values
	for (int i = 0; i < 16; i++)
	{
		bst.insert(i);
		avl.insert(i);
	}

//	system("pause");

	cout << "=============================" << endl;
	cout << "======= PRINTING TREE =======" << endl;
	cout << "=============================" << endl;

	//bst.printTree();
	avl.printTree();
	cout << endl;

//	system("pause");

#pragma region NodesTest

	cout << "=============================" << endl;
	cout << "====== NUMBER OF NODES ======" << endl;
	cout << "=============================" << endl;

	//starting clock
	time_point<Clock> start = Clock::now();

	//Run function
	//cout << bst.numNodes() << endl;
	cout << avl.numNodes() << endl;


	// Stop Clock
	time_point<Clock> end = Clock::now();
	milliseconds diff = duration_cast<milliseconds>(end - start);

	cout << "Function took: " << diff.count() << "ms" << endl;

//	system("pause");
#pragma endregion 
	
#pragma region LeavesTest

	cout << "=============================" << endl;
	cout << "===== NUMBER OF LEAVES ======" << endl;
	cout << "=============================" << endl;

	//starting clock
	start = Clock::now();

	//Running function
	//cout << bst.numLeaves() << endl;
	cout << avl.numLeaves() << endl;

	
	// Stop Clock
	end = Clock::now();
	//Compare start and end time
	diff = duration_cast<milliseconds>(end - start);

	cout << "Function took: " << diff.count() << "ms" << endl;

//	system("pause");

#pragma endregion 

#pragma region FullNodeTest

	cout << "=============================" << endl;
	cout << "==== NUMBER OF FULLNODES ====" << endl;
	cout << "=============================" << endl;

	//starting clock
	start = Clock::now();

	//Running function
	//cout << bst.numFullNodes() << endl;
	cout << avl.numFullNodes() << endl;

	// Stop Clock
	end = Clock::now();
	//Compare start and end time
	diff = duration_cast<milliseconds>(end - start);

	cout << "Function took: " << diff.count() << "ms" << endl;


#pragma endregion 

#pragma region Transverse

	cout << "=============================" << endl;
	cout << "==== PREORDER TRANSVERSAL ===" << endl;
	cout << "=============================" << endl;

	avl.preOrderTrans();

	cout << "=============================" << endl;
	cout << "=== POSTORDER TRANSVERSAL ===" << endl;
	cout << "=============================" << endl;

	avl.postOrderTrans();

	cout << "=============================" << endl;
	cout << "==== INORDER TRANSVERSAL ====" << endl;
	cout << "=============================" << endl;

	avl.inOrderTrans();

	cout << "=============================" << endl;
	cout << "=== LEVELORDER TRANSVERSAL ==" << endl;
	cout << "=============================" << endl;

	avl.levelOrderTrans();

#pragma endregion 



	system("pause");
	return 0;
}