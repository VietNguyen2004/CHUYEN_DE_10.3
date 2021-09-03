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
    int res = INT_MAX;
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    quickSort(a,1,n);
    for(int i = 1;i < n;i++)
        res = min(res,abs(a[i] - a[i+1]));
    cout<<res;
}
