#include<iostream>
#include<algorithm>
using namespace std;
long long  a[10000000];

int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i++) cin >>a[i];
    sort(a,a+n);
    int t;
    cin >> t;
    int x;
    while(t--)
    {
        cin >> x;
        cout<<boolalpha<<binary_search(a,a+n,x)<<endl;
    }

}
