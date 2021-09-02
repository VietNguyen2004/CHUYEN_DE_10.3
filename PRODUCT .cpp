#include<iostream>
using namespace std;
int a[10000000];
int b[10000000];
void quickSort(int arr[],int l , int r)
{
    int i = l;
    int j = r;
    int m = (l + r)/2;
    while(i < j)
    {
        while(arr[i]< arr[m]) i ++;
        while(arr[j]> arr[m]) j --;
        if(i <= j) swap(arr[i++],arr[j--]);
    }
    if(l < j) quickSort(arr,l,j);
    if(i < r) quickSort(arr,i,r);
}

int binarySearch(int a[],int l, int r,int x)
{
    while(l < r)
    {
        int m = (l + r)/2;
        if(a[m] >= x) r = m;
        else l = m + 1;
    }
    if(a[l] == x) return l;
    return -1;
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i = 1;i <= n;i ++)cin >> a[i];
    for(int i = 1;i <= m ;i++) cin>> b[i];

    quickSort(a,1,n);
    quickSort(b,1,m);
    int res = 0;
    for(int i=1;i <= n ; i++)
    {
        if(k % a[i]!= 0) continue;
        int id = binarySearch(b,1,m,k / a[i]) ;
        if(id != -1)
        {
            int c  = b[id];
            while(b[id] == c) {
                res ++;
                id++;
            }
        }
    }
    cout<<res;
}
