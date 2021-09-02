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
    int a,b,n,d;
    cin >> a >> b>> n >> d;
    int ngang[10000];
    int doc[10000];
    for(int i = 1;i <=n ; i++) cin >> ngang[i];
    for(int i = 1;i <= d;i ++) cin>> doc[i];
    ngang[0] = 0;
    ngang[n +1] = a;
    doc[0] = 0;
    doc[d+1] = b;
    quickSort(ngang,0,n+1);
    quickSort(doc,0,n+1);

    int l = INT_MIN;
    int w = INT_MIN;

    for(int i = 0;i <= n;i ++) l = max(l,ngang[i+1] - ngang[i]);
    for(int i = 0;i <= d;i ++) w = max(w,doc[i+1] - doc[i]);
    cout<<l * w;

}
