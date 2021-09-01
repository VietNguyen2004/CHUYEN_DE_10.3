/*Yêu cầu: Có n học sinh, mỗi học sinh có 3 thông tin: Họ tên, điểm toán, điểm tin. Sắp xếp danh sách học sinh theo tiêu chí:
         -  Họ tên tăng dần.
         -  Nếu họ tên giống nhau thì tổng điểm (= điểm toán + điểm tin) tăng dần.
         -  Nếu họ tên và tổng điểm giống nhau thì điểm toán tăng dần.
*/

#include<iostream>
using namespace std;
struct student
{
    string name;
    int math;
    int it;
};
student arr[100000];
int compare_string(string a, string b)
{
    if(a == b) return 0;
    int k = max(a.size(),b.size());
    while(a.size() < k) a += " ";
    while(b.size() < k) b += " ";
    for(int i = 0;i < k ; i ++)
    {
        if(a[i] > b[i]) return 1;
        else if(a[i] < b[i]) return 2;
    }
}

int compare_int(int a, int b)
{
    if(a > b) return 1;
    if(a < b) return 2;
    return 0;
}
int compare(student a, student b)
{
    if(a.name != b.name)
        return compare_string(a.name,b.name);
    int k1= a.math + a.it;
    int k2 = b.math + b.it;
    if(k1 != k2) return compare_int(k1,k2);
    return compare_int(a.math,b.math);
}

void quickSort(int l,int r)
{
    int i = l;
    int j = r;
    int mid = (l + r) / 2;
    while(i < j)
    {
        while(compare(arr[i],arr[mid]) == 2) i ++;
        while(compare(arr[j],arr[mid]) == 1) j --;
        if(i <= j)
            swap(arr[i++],arr[j--]);
    }
    if(i < r) quickSort(i,r);
    if(j > l) quickSort(l,j);
}
int main()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n ;i ++ )
        cin >> arr[i].name >> arr[i].math >> arr[i].it;
    quickSort(1,n);
    cout<<endl;
    for(int i = 1;i <= n;i ++)
        cout<<arr[i].name<<" "<<arr[i].math<<" "<<arr[i].it<<endl;
}
