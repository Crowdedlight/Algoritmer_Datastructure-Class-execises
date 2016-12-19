#include "QuickSort.h"



QuickSort::QuickSort()
{
}

void QuickSort::quickSort(vector<int> & a)
{
    quickSort(a, 0, a.size() - 1);
}

void QuickSort::quickSort(vector<int> & a, int left, int right)
{
    //cutoff
    if (left + 10 <= right)
    {
        const int pivot = median3(a, left, right);

        //Begin partitioning
        int i = left, j = right-1;
        for (; ;)
        {
            //moves the pointers in each edge in until they find a place to swap
            while (a[++i] < pivot) {}
            while (pivot < a[--j]) {}
            if (i < j)
                swap(a[i], a[j]);
            else
                break;
        }

        //Restore pivot
        swap(a[i], a[right - 1]);

        //Sort smaller elements
        quickSort(a, left, i - 1);
        //sort larger elements
        quickSort(a, i + 1, right);
    }
    else
        insertionSort(a, left, right);
}

void QuickSort::insertionSort(vector<int> & a, int left, int right)
{
    int j;

    for (int i = left; i <= right; i++)
    {
        j = i;

        while (j > left && a[j] < a[j - 1])
        {
            int tmp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = tmp;
            j--;
        }
    }
}

const int QuickSort::median3(vector<int> & a, int left, int right)
{
    int center = (left + right) / 2;

    //Sort the three to get middle for pivot point and already have the edges sorted
    if (a[center] < a[left])
        swap(a[left], a[center]);
    if (a[right] < a[left])
        swap(a[left], a[right]);
    if (a[right] < a[center])
        swap(a[center], a[right]);

    //place pivot point at position right -1
    swap(a[center], a[right - 1]);
    return a[right - 1];
}

void QuickSort::print(vector<int> a)
{
    for (auto i : a)
    {
        cout << i << ",";
    }

    cout << endl;
}


QuickSort::~QuickSort()
{
}
