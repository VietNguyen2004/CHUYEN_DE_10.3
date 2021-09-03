#include<iostream>
#include<algorithm>
using namespace std;
int a[10000000];


int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 0;i < m;i++) cin>>a[i];
    sort(a,a+ m);
    int res = 0;
    for(int i = 0;i < m-1;i ++) res = max((a[i+1]-a[i])/2,res);
    res = max(a[0],res);
    res = max(res,n - a[m-1]);
    cout<<res;
}
