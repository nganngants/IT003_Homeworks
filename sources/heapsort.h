#include <bits/stdc++.h>

#define ll long long

using namespace std;

void heapify (ll a[], int i, int n)
{
    int Max = i;
    int l = i << 1 | 1;
    int r = l + 1;
    if (l < n && a[l] > a[Max]) Max = l;
    if (r < n && a[r] > a[Max]) Max = r;
    if (Max != i)
    {
        swap(a[Max], a[i]);
        heapify(a,Max,n);
    }
}

void heapSort(ll a[], int n)
{
    for (int i=n/2-1;i>=0;--i)
        heapify(a,i,n);
    for (int i=n-1;i>0;--i)
    {
        swap(a[i], a[0]);
        heapify(a,0,i);
    }
}


