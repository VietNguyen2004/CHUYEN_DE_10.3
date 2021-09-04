#include<iostream>
#include<algorithm>
using namespace std;
long long  a[10000000];
void quickSort(long long  arr[],int l , int r)
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
    int t = 0;
    int n,m;
    cin >> n >> m;
    int i ;
    for(i = 1;i <= n;i++) {
        cin >>a[i];
        t += a[i];
    }
    quickSort(a,1,n);
    a[0] = 0;
    int s = 0;
    for(i = 1;i <= n;i ++)
    {
        s += (a[i] - a[i-1])*(n+1-i);
        if(t - s < m) break;
    }
    s -= (a[i]-a[i-1])*(n+1-i);
    int k = (t-s-m)/(n+1-i);
    cout<<a[i-1] + k;
}
