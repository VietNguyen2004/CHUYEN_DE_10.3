/*cho 2 dãy số , sắp xếp để tỉ số trọng đối của 2 dãy là nhỏ nhất */
#include<iostream>
#include<algorithm>
using namespace std;
int a[10000];
int b[10000];
int n;


int main()
{
    cin >> n ;
    for(int i = 0;i < n; i++)
        cin >> a[i];
    for(int i =0 ;i < n;i++)
        cin >> b[i];
    sort(a,a+n,greater<int>());
    sort(b,b+n);
    int res  = 0;
    for(int i = 0;i < n ;i++) res += a[i] * b[i];
    cout<<res;


}

