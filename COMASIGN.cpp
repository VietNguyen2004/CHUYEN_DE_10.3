/*
Trung tâm máy tính cần phân máy thực hành cho N lớp sinh viên (được đánh số từ 1 đến N). Lớp sinh viên i có Xi sinh viên. Trong trung tâm có M (MN) phòng máy được đánh số từ 1 
đến M. Phòng máy j có Yj máy. Để đảm bảo việc hướng dẫn thực hành, mỗi sinh viên cần có một máy, ngoài ra còn cần một máy cho giáo viên hướng dẫn. Không được phép di chuyển máy
từ phòng máy này sang phòng máy khác. 
Yêu cầu: Xác định số lượng lớn nhất các lớp sinh viên có thể đồng thời phân bố mỗi lớp vào một phòng máy và sao cho trong mỗi phòng máy mỗi sinh viên có một máy riêng để làm việc 
và ngoài ra còn một máy dành cho giáo viên hướng dẫn. 
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
int b[1000];
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i ++) cin >> a[i];
    for(int i = 1;i <= m ;i ++){
        cin >> b[i];
        b[i] --;
    }
    quickSort(a,1,n);
    quickSort(b,1,n);
    int j = 1;
    int res = 0;
    for(int i = 1;i <= n;i++)
    {
        while(b[j] < a[i])
        {
            j++;
            if(j > m)
            {
                cout<<res;
                return 0;
            }
        }
        res ++;
        j ++;
    }
    cout<<res;

}

