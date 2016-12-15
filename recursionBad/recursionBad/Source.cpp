#include <iostream>
#include <chrono>
using namespace std;

//Usings for chrono timetaker package
using std::chrono::time_point;
using Clock = std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::milliseconds;

int counter1 = 0;
int counter2 = 0;

int fibonacci(int n)
{
    counter1++;
    if (n == 1 || n == 2)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int fib(int n)
{
    if (n <= 1)
        return 1;

    int prev = 1;
    int result = 1;
    int sum;

    counter2 += 4; //4 lines computed before entering the loop

    for (int i = 2; i < n; ++i)
    {
        counter2++;
        sum = result + prev;
        prev = result;
        result = sum;
    }

    return result;
}

int main()
{
    //starting clock
    time_point<Clock> start;
    time_point<Clock> end;
    milliseconds diff;


    start = Clock::now();

    int res1 = fibonacci(30);

    // Stop Clock
    end = Clock::now();
    diff = duration_cast<milliseconds>(end - start);
    cout << "Recursive method took: " << counter1 << " instructions in: " << diff.count() << "ms" << endl;
    cout << "result: fib(30): " << res1 << endl;

    start = Clock::now();

    int res2 = fib(30);

    // Stop Clock
    end = Clock::now();
    diff = duration_cast<milliseconds>(end - start);
    cout << "Non-Recursive method took: " << counter2 << " instructions in: " << diff.count() << "ms" << endl;
    cout << "result: fib(30): " << res2 << endl;
    
    system("pause");


}