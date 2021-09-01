/*Đàn bò của nông dân BOP có N con bò và được đánh số thứ tự từ 1 đến N. Con bò thứ i có chỉ số sức khỏe là Si là một số nguyên dương (1  Si  1000), 
cặp hai con bò gồm con bò thứ i và con bò thứ j có sức mạnh là tích của chỉ số sức khỏe hai con bò đó (Si x Sj). BOP cần chọn trong đàn bò của mình ra K (1  K  N /2) 
cặp bò để tham gia một hội thi đấu bò sao cho tổng sức mạnh của K cặp bò là lớn nhất. (Kí hiệu X 
là phần nguyên của X). 
Hãy giúp BOP thực hiện công việc trên.  
*/
#include<iostream>
#include<algorithm>
using namespace std;

void quickSort(int arr[], int l,int r)
{
    int i = l;
    int j = r;
    int mid = (l + r) / 2;
    while(i < j)
    {
        while(arr[i] < arr[mid]) i ++;
        while(arr[j] > arr[mid]) j --;
        if(i <= j)
            swap(arr[i++],arr[j--]);
    }
    if(i < r) quickSort(arr,i,r);
    if(j > l) quickSort(arr,l,j);
}
int a[1000];

int main()
{
    int n,k;
    cin >> k >> n ;
    for(int i = 1;i <= n;i ++) cin >> a[i];

    quickSort(a,1,n);

    int res = 0;
    for(int i = n; i >= 1; i -=2)
    {
        res += a[i] * a[i-1];
        k --;
        if(k == 0) break;
    }
    cout<<res;
}

