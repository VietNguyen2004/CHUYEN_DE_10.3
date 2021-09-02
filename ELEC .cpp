/* tìm số ở cắm rời ít nhất cho m máy tính, có 1 ổ cắm có địn trên trường*/
#include<iostream>

using namespace std;


void quickSort(int arr[],int l,int r)
{
    int i = l;
    int j = r;
    int mid = (l + r) / 2;
    while(i < j)
    {
        while(arr[i] > arr[mid]) i ++;
        while(arr[j] < arr[mid]) j --;
        if(i <= j){
            swap(arr[i],arr[j]);
            i ++;
            j --;
        }
    }
    if(i < r) quickSort(arr,i,r);
    if(j > l) quickSort(arr,l,j);

}

int a[1000000];
int main()
{
    int n,m;
    cin >> n >> m ;
    for(int i =1 ;i <= n;i ++) cin >> a[i];
    quickSort(a,1,n);
    int res = 0;
    int comp = 1;
    for(int i = 1;i <= n;i ++)
    {
        comp *= a[i];
        res ++;
        if(comp >= m) break;
    }
    cout<<res;

}

