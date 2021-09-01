/*Quốc vương muốn tổ chức một nhánh kỵ binh, vì vậy ông muốn bắt kk con rồng để chuẩn bị cho nhánh kỵ binh ấy. Quốc vương đem theo nn kỵ sĩ 
và chuẩn bị cho mỗi người nhiệm vụ bắt một con rồng. Mỗi kỵ sĩ chỉ bắt được con rồng có chỉ số sức mạnh thấp hơn họ. Mỗi con rồng có một chỉ 
số DiDi là sức mạnh của nó, mỗi kỵ sĩ ii thì có chỉ số sức mạnh là HiHi. Quốc vương muốn biết là có thể bắt được tất cả các con rồng hay khôn
g, nếu có hãy cho quốc vương biết tổng sức mạnh thấp nhất của các kỵ sĩ dùng để bắt rồng. Cho số liệu của các con rồng và kỵ sĩ, tính tổng sức
mạnh nhỏ nhất trong trường hợp bắt được hoặc trả lời không.
*/
#include<iostream>
using namespace std;

int man[1000];
int dragon[1000];


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
    int n,k;
    cin >> n >> k ;
    if(n < k)
    {
        cout<<"NO";
        return 0;
    }
    int res = 0;
    for(int i = 1;i <= n;i ++) cin >> man[i];
    for(int i = 1;i <= k ; i++) cin >> dragon[i];
    int id = 1;
    quickSort(man,1,n);
    quickSort(dragon,1,k);
    for(int i = 1;i <= k ;i ++)
    {
        while(dragon[i] > man[id])
        {
            id ++;
            if(id > n)
            {
                cout<<"NO";
                return 0;
            }
        }
        res += man[id];
        id++;
    }
    cout<<res;

}


