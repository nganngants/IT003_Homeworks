#include <bits/stdc++.h>

#define ll long long

using namespace std;

void quicksort(ll a[], int l, int r)
{
    int mid = (l + r) / 2;
    ll x = a[mid];
    int i = l, j = r;
    do
    {
        while (a[i] < x && i <= j) i++;
        while (a[j] > x && j >= i) j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++; j--;
        }
    } while (i <= j);
    if (i < r) quicksort(a, i, r);
    if (l < j) quicksort(a, l, j);
}

void quickSort(ll a[], int n)
{
    quicksort(a,0,n-1);
}
