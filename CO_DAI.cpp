#include<iostream>

using namespace std;
int a[10000000];


int main()
{
    int a = INT_MIN;
    int b = INT_MAX;
    int n;
    int x;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> x;
        a = max(a,x);
        b = min(b,x);
    }
    cout<<a - b;

}
