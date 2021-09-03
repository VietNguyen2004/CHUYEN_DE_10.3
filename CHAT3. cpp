#include<iostream>

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
int bin_search(long long a[],int l,int r,int x)
{
    int res = -1;
    while(l <= r)
    {
        int m = (l+r)/2;
        if(a[m] <= x)
        {
            res = m;
            l = m + 1;
        }else r = m - 1;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) cin >>a[i];
    quickSort(a,1,n);
    int t;
    for(int i =1 ;i <= n;i++) cout<< a[i] <<" ";
    cin >> t;
    int x;
    while(t --)
    {
        cin >> x;
        int k = bin_search(a,1,n,x);
        if(k != -1) cout<<a[k]<<endl;
    }
}
