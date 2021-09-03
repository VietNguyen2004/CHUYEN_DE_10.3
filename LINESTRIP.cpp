#include<iostream>

using namespace std;



int main()
{
    int a = INT_MAX;
    int b = INT_MIN;
    int n,x;
    cin >> n;
    while(n--)
    {
        cin >> x;
        a = min(a,x);
        b = max(b,x);
    }
    if(b < 0) cout<< -2 * a;
    else if(a >0 ) cout<< 2* b;
    else cout<<2*(b-a);
}
