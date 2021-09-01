/*
Sắp tới là Trung thu, nhóm bạn của An quyết định sẽ đến thăm trại trẻ mồ côi XYZ. Ở đây có khá nhiều những đứa trẻ đáng yêu và ngoan ngoãn. Các em rất thích ăn Chocolate
, nên An và nhóm bạn quyết định mua một ít cho chúng. 
Tại siêu thị MaxiMark có N loại Chocolate (được đánh số từ 1..N) với số lượng mỗi loại không hạn chế. Loại thứ i có giá Pi (nghìn đồng) và có đúng Ci em bé muốn ăn loại
Chocolate ấy. Nhóm An có B (nghìn đồng) để mua Chocolate cho bọn trẻ. 
Hỏi số em bé tối đa mà nhóm An có thể mua Chocolate cho là bao nhiêu? Biết rằng mỗi em bé chỉ thích một loại Chocolate và bé chỉ ăn được loại Chocolate ấy. 
*/

#include<iostream>
#include<algorithm>
using namespace std;

struct candy{
    int price;
    int counts;
};
candy arr[100000];
void quickSort( int l,int r)
{
    int i = l;
    int j = r;
    int mid = (l + r) / 2;
    while(i < j)
    {
        while(arr[i].price < arr[mid].price) i ++;
        while(arr[j].price > arr[mid].price) j --;
        if(i <= j)
            swap(arr[i++],arr[j--]);
    }
    if(i < r) quickSort(i,r);
    if(j > l) quickSort(l,j);
}
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i ++)
        cin >> arr[i].price>>arr[i].counts;
    int c = 0;
    quickSort(1,n);
    for(int i = 1;i <= n;i++)
    {
        if(arr[i].price * arr[i].counts <= m) {
            c += arr[i].counts;
            m -= arr[i].price * arr[i].counts ;
        }
        else {
            cout<<c<<endl;
            c += (m / arr[i].price);
            break;
        };
    }
    cout<<c;

}


