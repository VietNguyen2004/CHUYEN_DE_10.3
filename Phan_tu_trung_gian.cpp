/*tìm phần tử ở ở giữa dãy */
#include<iostream>
#include<algorithm>
using namespace std;
int a[100000];
int n,k;
void quickSort(int arr[],int l,int r)
{
    if(l <= k && k <= r)
    {
        int i = l;
        int j = r;
        int mid = (l + r) / 2;
        while(i < j)
        {
            while(arr[i] < arr[mid]) i ++;
            while(arr[j] > arr[mid]) j --;
            if(i <= j){
                swap(arr[i],arr[j]);
                i ++;
                j --;
            }
        }
        if(i < r) quickSort(arr,i,r);
        if(j > l) quickSort(arr,l,j);
    }
}


int main()
{
    cin >> n ;
    k = n/2 + 1;
    for(int i = 1;i <= n; i++)
        cin >> a[i];
    quickSort(a,1,n);
    cout<<a[k];


}

