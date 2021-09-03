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
        while(arr[i] >  arr[m]) i ++;
        while(arr[j] < arr[m]) j --;
        if(i <= j) swap(arr[i++],arr[j--]);
    }
    if(l < j) quickSort(arr,l,j);
    if(i < r) quickSort(arr,i,r);
}



int main()
{
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n; i++) cin >> a[i];
    quickSort(a,1,n);
    int res = 0;
    for(int i = 1;i <= k ; i++) res += a[i];
    cout<<res;

}
