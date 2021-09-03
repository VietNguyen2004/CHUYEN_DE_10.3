#include<iostream>
#include<math.h>
using namespace std;



int solve(int n)
{
    int res;
    double k = sqrt(n-1);
    if(k == int(k) & k != 0) return n;
    res = int(k) + 1;
    return res *res + 1;

}


int main()
{
    int n;
    cin >> n;
    int t;
    cin >> t;
    int x;
    int i = 1;
    while(t--)
    {
        cin >> x;
        cout<<solve(x)<<endl;
    }

}
