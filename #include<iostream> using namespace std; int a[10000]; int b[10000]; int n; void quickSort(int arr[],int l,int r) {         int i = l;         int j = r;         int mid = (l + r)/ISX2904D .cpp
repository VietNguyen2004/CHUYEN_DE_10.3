#include<iostream>
using namespace std;
int a[10000];
int b[10000];
int n;
void quickSort(int arr[],int l,int r)
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


int main()
{
    cin >> n  ;
    for(int i = 1;i <= n; i++)
        cin >> a[i];
    for(int i =1 ;i <= n;i++)
        cin >> b[i];
    quickSort(a,1,n);
    quickSort(b,1,n);
    int res = 0;
    for(int i = 1;i <= n;i++) res += abs(a[i] - b[i]);
    cout<<res;


}

