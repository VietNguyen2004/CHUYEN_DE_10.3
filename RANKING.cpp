#include<iostream>
#include<map>
using namespace std;

struct cmp
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};


int main()
{
    int n;
    int x;
    cin >> n;
    map<int,int,cmp> m;
    while(n--)
    {
        cin >> x;
        m[x] ++;
    }
    int res = 0;
    int mark = 1;
    for(auto p : m)
    {
        res += p.second * mark;
        mark ++;
    }
    cout<<res;
}
