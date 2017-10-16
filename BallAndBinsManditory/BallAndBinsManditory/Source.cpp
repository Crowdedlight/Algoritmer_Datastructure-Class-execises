#pragma once
#include "BinCollection.h"

int main()
{
	cout << "What is the maximum number of balls in a bin if 10,007 balls are randomly distributed in an equal number of bins ? " << endl;

	BinCollection bc(10007);
	BinCollection bcLarge(1000000);

	cout << "Doing the experiment 10 times and taking an average of bin with most balls" << endl;

#pragma region normal10007

	cout << "----------------------------------------" << endl;
	cout << "---------- NORMAL BALLS/BINS -----------" << endl;
	cout << "----------- 10007 bins/balls -----------" << endl;
	cout << "----------------------------------------" << endl;

	int average = 0;
	int attempts = 1000;
	for(auto i = 1; i <= attempts; i++)
	{
		bc.putBalls(10007);		
		int tempLarge = bc.findLargestBin();

		//cout << "Attempt: " << i << " = " << tempLarge << endl;

		average += tempLarge;

		//Clear bins
		bc.clear();
	}

	//get average
	average = average / attempts;

	cout << "Average amounts in the bin with most balls is: " << average << endl;
	//Calculated value
	int cal = log(10007)/(log(log(10007)));
	cout << "Calculted average per bin: " << cal << endl << endl;
	system("pause");

#pragma endregion 

#pragma region normal1000000

	cout << "----------------------------------------" << endl;
	cout << "---------- NORMAL BALLS/BINS -----------" << endl;
	cout << "---------  1000000 bins/balls  ---------" << endl;
	cout << "----------------------------------------" << endl;


	average = 0;
	attempts = 1000;

	for (auto i = 1; i <= attempts; i++)
	{
		bcLarge.putBalls(1000000);
		int tempLarge = bcLarge.findLargestBin();

		//cout << "Attempt: " << i << " = " << tempLarge << endl;

		average += tempLarge;

		//Clear bins
		bcLarge.clear();
	}

	//get average
	average = average / attempts;

	cout << "Average amounts in the bin with most balls is: " << average << endl;
	//Calculated value
	int cal2 = log(1000000) / (log(log(1000000)));
	cout << "Calculted average per bin: " << cal2 << endl << endl;

	system("pause");

#pragma endregion 

#pragma region PowerOfTwo10007

	/// POWER OF TWO CHOICES

	cout << "----------------------------------------" << endl;
	cout << "--------- POWER OF TWO CHOICES ---------" << endl;
	cout << "----------  10007 bins/balls  ----------" << endl;
	cout << "----------------------------------------" << endl;

	average = 0;
	attempts = 1000;

	for (auto i = 1; i <= attempts; i++)
	{
		bc.putBallsPof2(10007);
		int tempLarge = bc.findLargestBin();

		//cout << "Attempt: " << i << " = " << tempLarge << endl;

		average += tempLarge;

		//Clear bins
		bc.clear();
	}

	//get average
	average = average / attempts;

	cout << "Average amounts in the bin with most balls is: " << average << endl;
	//Calculated value
	int cal3 = log(log(10007));
	cout << "Calculted average per bin: " << cal3 << endl << endl;

	system("pause");

#pragma endregion 

#pragma region PowerOfTwo1000000

	/// POWER OF TWO CHOICES

	cout << "----------------------------------------" << endl;
	cout << "--------- POWER OF TWO CHOICES ---------" << endl;
	cout << "---------  1000000 bins/balls  ---------" << endl;
	cout << "----------------------------------------" << endl;

	average = 0;
	attempts = 1000;

	for (auto i = 1; i <= attempts; i++)
	{
		bcLarge.putBallsPof2(1000000);
		int tempLarge = bcLarge.findLargestBin();

		//cout << "Attempt: " << i << " = " << tempLarge << endl;

		average += tempLarge;

		//Clear bins
		bcLarge.clear();
	}

	//get average
	average = average / attempts;

	cout << "Average amounts in the bin with most balls is: " << average << endl;
	//Calculated value
	int cal4 = log(log(1000000));
	cout << "Calculted average per bin: " << cal4 << endl << endl;

	system("pause");

#pragma endregion 

	return 0;
}