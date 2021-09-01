/*Cho hai dãy số nguyên dương gồm   phần tử   và  . Đặt  , tức là khi sắp xếp lại dãy   theo một thứ tự nào đó, giá trị   luôn theo kèm và phụ thuộc với giá trị 
 . Bạn cần sắp xếp dãy   thỏa mãn với mọi cặp   và   mà  	 thì  	 hoặc    và  	. 
*/
#include<iostream>
using namespace std;
int a[10000];
int b[10000];
void quickSort(int l,int r)
{
    int i = l;
    int j = r;
    int mid = (l + r) / 2;
    while(i < j)
    {
        while((a[i] < a[mid]) || (a[i] == a[mid] && b[i] > b[mid])) i ++;
        while((a[j] > a[mid]) || (a[j] == a[mid] && b[j] < b[mid])) j --;
        if(i <= j){
            swap(b[i],b[j]);
            swap(a[i],a[j]);
            i ++;
            j --;
        }
    }
    if(i < r) quickSort(i,r);
    if(j > l) quickSort(l,j);
}

int main()
{
    int n;
    cin >> n ;
    for(int i = 0;i < n;i ++)cin >> a[i];
    for(int i = 0;i < n;i ++)cin >> b[i];
    quickSort(0,n-1);
    for(int i = 0; i < n; i ++)
        cout<< a[i]<<" "<<b[i]<<endl;

}


