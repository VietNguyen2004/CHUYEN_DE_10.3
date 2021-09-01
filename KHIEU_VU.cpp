/* Để chuẩn bị cho tiết mục văn nghệ chào mừng kĩ niệm ngày thành lập Đoàn sắp đến, thầy phụ trách công tác văn nghệ cần chọn ra
một cặp học sinh tham gia biểu diễn tiết mục khiêu vũ thể thao. Cặp được chọn gồm một học sinh nam và một học sinh nữ. Để đảm bảo
tính thẩm mĩ thì bạn nam phải không thấp hơn bạn nữ và cũng không cao hơn bạn nữ quá K milimét. 
Sau một thời gian thông báo, đã có N học sinh đăng kí tham gia. Danh sách này gồm có hai thông tin là chiều cao và giới tính
*/
#include<iostream>
#include<algorithm>
using namespace std;

int nam[10000];
int nu[10000];

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
int main()
{
    int n,k,x;
    int res = 0;
    int id_nam = 0;
    int id_nu = 0;
    cin >> n >> k ;
    for(int i = 0;i < n; i ++)
    {
        cin >> x;
        if(x > 0) nam[id_nam++] = x;
        else nu[id_nu++] = abs(x);
    }
    quickSort(nam,0,id_nam -1);
    quickSort(nu,0,id_nu - 1);

    for(int i = 0;i < id_nam;i ++)
    {
        int start = lower_bound(nu,nu+id_nu,nam[i]-k) - nu;
        int ends = upper_bound(nu,nu+id_nu,nam[i]) - nu;
        res += ends - start;
    }
    cout<<res;
}



