#include<iostream>
using namespace std;

int n,k;
int a[100000000];

bool f(int m)
{
    int res = 0;
    for(int i = 1;i<= n;i++) res += a[i] / m;
    if(res >= k) return true;
    return false;
}

int main()
{
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];
    int r = 1000000000;
    int l= 1;
    int result = -1;
    while(l <= r)
    {
        int m = (r + l)/2;
        if(f(m))
        {
            result = m;
            l = m + 1;
        }
        else r = m - 1;
    }
    cout<<result;
    return 0;
}

