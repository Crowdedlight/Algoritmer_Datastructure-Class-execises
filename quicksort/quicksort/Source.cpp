#include <iostream>
#include "QuickSort.h"
#include <vector>
#include <random>
#include <chrono>

using namespace std;

//Usings for chrono timetaker package
using std::chrono::time_point;
using Clock = std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::milliseconds;

int main()
{
    //starting clock
    time_point<Clock> start;
    time_point<Clock> end;
    milliseconds diff;

    random_device rd;

    QuickSort sort;

    vector<int> samples;

    for (auto i = 0; i < 50000; i++)
    {
        int tmp = rd() % 10000;
        samples.push_back(tmp);
    }


    cout << "---------------------------------------" << endl;
    cout << "----------- UNSORTED ARRAY ------------" << endl;
    cout << "---------------------------------------" << endl;
    //sort.print(samples);


    cout << "---------------------------------------" << endl;
    cout << "-------------- SORTING ----------------" << endl;
    cout << "---------------------------------------" << endl;
    //timing
    start = Clock::now();

    sort.quickSort(samples);

    //timing end
    end = Clock::now();
    diff = duration_cast<milliseconds>(end - start);
    cout << "Function took: " << diff.count() << "ms" << endl;

    cout << "---------------------------------------" << endl;
    cout << "------------ SORTED ARRAY -------------" << endl;
    cout << "---------------------------------------" << endl;

    //sort.print(samples);

    system("pause");
}