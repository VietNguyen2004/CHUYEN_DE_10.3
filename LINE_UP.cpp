/*Cho n thanh gỗ hãy sắp xếp các thành gỗ thành các hàng sao cho ít hàng nhất có thể, biết thanh gỗ có chiều rộng w2 và chiều dài l2sắp được sau thanh gỗ có chiều rộng là w1 chiều dài l1 
nếu w2<w1và l2<l1 , tìm số hàng ít nhất */
#include<iostream>
using namespace std;
int length[10000];
int width[100000];
void quickSort(int l, int r)
{
    int i = l;
    int j = r;
    int mid = (l + r) /2 ;
    while(i < j)
    {
        while(length[i] < length[mid] || (length[i] == length[mid] && width[i]  < width[mid])) i ++;
        while(length[j] > length[mid] || (length[j] == length[mid] && width[j] > width[mid])) j --;
        if(i <= j)
        {
            swap(length[i],length[j]);
            swap(width[i],width[j]);
            i ++;
            j --;
        }
    }
    if(l < j) quickSort(l,j);
    if(i < r) quickSort(i,r);
}

int main()
{
    int t,n;
    cin >> t;
    for(;t >0;t--)
    {
        cin >> n;
        for(int i = 1;i <= n;i++) cin >> length[i] >> width[i];
        quickSort(1,n);
        int id = 1;
        int res = 0;
        while(id <= n)
        {
            res ++;
            while(id < n && (length[id] < length[id+1] && width[id] <width[id + 1])) id ++;
            id ++;
        }
        cout<<res <<endl;
    }
}
