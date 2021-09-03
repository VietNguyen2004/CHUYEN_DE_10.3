#include<iostream>

using namespace std;
int a[10000000];
void quickSort(int arr[],int l , int r)
{
    int i = l;
    int j = r;
    int m = (l + r)/2;
    while(i < j)
    {
        while(arr[i] <  arr[m]) i ++;
        while(arr[j] > arr[m]) j --;
        if(i <= j) swap(arr[i++],arr[j--]);
    }
    if(l < j) quickSort(arr,l,j);
    if(i < r) quickSort(arr,i,r);
}


int main()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    int res = INT_MAX;
    quickSort(a,1,n);
    for(int i = 1;i < n;i++) res = min(res,a[i + 1] - a[i]);
    cout<<res;
}
