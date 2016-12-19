#pragma once
#include <vector>
#include <iostream>

using namespace std;
class QuickSort
{
public:
    QuickSort();    
    ~QuickSort();

    void quickSort(vector<int> & a);
    void print(vector<int> a);

private:
    void quickSort(vector<int> & a, int left, int right);
    const int median3(vector<int> & a, int left, int right);
    void insertionSort(vector<int> & a, int left, int right);
};

