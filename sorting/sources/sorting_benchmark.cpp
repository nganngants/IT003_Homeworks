#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "csort.h"
#include "heapsort.h"
#include "quicksort.h"
#include "mergesort.h"

#define N 1000000
#define TESTCASE 10

using namespace std;

int n;
ll raw[N], a[N];

string tostr(int x)
{
    if (x < 10)
    {
        string s = "0";
        s += char(x + '0');
        return s;
    }
    return "10";
}

void readTestCase(int test)
{
    string name = "input" + tostr(test) + ".txt";
    cout << "Testing on test " << test << "...\n";
    ifstream fi(name.c_str());
    fi >> n;
    for (int i = 0; i < n; ++i) fi >> raw[i];
    fi.close();
}

double benchmark(void (*func)(ll arr[], int n))
{
    for (int i = 0; i < n; ++i)
        a[i] = raw[i];
    clock_t t_begin = clock();
    func(a, n);
    clock_t t_end = clock();
    return double(t_end - t_begin) / CLOCKS_PER_SEC * 1000;
}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ofstream fo("results.txt");
    fo << "QuickSort\tHeapSort\tMergeSort\tSTLSort\n";
    for (int test = 1; test <= TESTCASE; ++test)
    {
        readTestCase(test);
        fo << benchmark(quickSort) << '\t' << setw(10);
        fo << benchmark(heapSort) << '\t' << setw(10);
        fo << benchmark(mergeSort) << '\t' << setw(10);
        fo << benchmark(cSort) << '\n';
    }
    cout << "Done!!";
    return 0;
}
