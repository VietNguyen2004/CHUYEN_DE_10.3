#include<iostream>
#include<map>
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
int c[10000][10000];
int comb(int n,int k)
{
    if(c[n][k] != 0) return c[n][k];
    else if(k == 0 || k == n)
        c[n][k] = 1;
    else c[n][k] = comb(n-1,k-1) + comb(n-1,k);
    return c[n][k];
}

int main()
{
    c[0][0] = 1;
    map<int,int> m;
    int x;
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> x;
        m[x] ++;
    }
    int result = 0;
    for(auto p : m)
    {
        if(p.second >= 3){
            result += comb(p.second,3);
        }
    }
    cout<<result;
}
