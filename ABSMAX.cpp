#include<iostream>
#include<map>
using namespace std;
int a[10000000];
int main()
{
    int a1 = INT_MAX;
    int a2 = INT_MAX;
    int b1 = INT_MIN;
    int b2 = INT_MIN;
    int n,x;
    cin >> n;
    while(n--)
    {
        cin >> x;
        if(x > b1)
        {
            b2 = b1;
            b1 = x;
        }
        else if(x > b2 && x < b1) b2 = x;

        if(x < a1)
        {
            a2 = a1;
            a1 = x;
        }
        else if(x < a2 && x > a1) a2 = x;
    }
    cout<<max(abs(a1+a2) , abs(b1+b2));
}
