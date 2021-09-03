#include<iostream>
#include<map>
using namespace std;


int main()
{
    map<int,int> m;
    int n,x;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> x;
        m[x] ++;
    }
    for(auto p: m) if(p.second&1) {
        cout<<p.first;
        break;
    }
}
