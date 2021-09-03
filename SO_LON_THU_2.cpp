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
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int n;
    int x;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> x;
        if(x > max1) {
            max2 = max1;
            max1 = x;
        }
        else if(x > max2 && x < max1)
            max2 = x;
    }
    cout<<max2;

}
