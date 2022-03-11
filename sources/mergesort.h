#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll L[1000000], R[1000000];

void merge(ll a[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    for (i = 0; i < n1; i++) L[i] = a[l + i];
    for (j = 0; j < n2; j++) R[j] = a[m + 1 + j];
    i = j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]) a[k] = L[i++];
        else a[k] = R[j++];
        k++;
    }
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

void mergesort(ll a[], int l, int r)
{
    //cout << l << " " << r << " " << mid << '\n';
    if (l >= r) return ;
    int mid = (l + r) / 2;
    mergesort(a, l, mid);
    mergesort(a, mid+1, r);
    merge(a, l, mid, r);
}

void mergeSort(ll a[], int n)
{
    mergesort(a,0,n-1);
}
