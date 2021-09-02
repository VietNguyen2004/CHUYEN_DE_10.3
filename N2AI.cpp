#include<iostream>
#include<algorithm>
using namespace std;
int a[10000000];



int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < 2 * n;i ++) cin >> a[i];
    sort(a,a+n);
    sort(a+n,a+2*n,greater<int>());
    for(int i = 0;i < 2* n;i ++) cout<<a[i]<<" ";

}
