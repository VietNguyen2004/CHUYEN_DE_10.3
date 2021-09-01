/*TÌM PHÂN SỐ NHỎ THỨ K */
 #include<iostream>
using namespace std;
double a[10000];
double b[10000];
int n,k ;
void quickSort(int l,int r)
{
    if(l <= k && k <= r){
        int i = l;
        int j = r;
        int mid = (l + r) / 2;
        while(i < j)
        {
            while(a[i]/b[i] < a[mid]/b[mid]) i ++;
            while(a[j]/b[j] > a[mid]/b[mid]) j --;
            if(i <= j){
                swap(b[i],b[j]);
                swap(a[i],a[j]);
                i ++;
                j --;
            }
        }
        if(i < r) quickSort(i,r);
        if(j > l) quickSort(l,j);
    }
}

int gcd(int a,int b)
{
    while(b != 0)
    {
        swap(a,b);
        b %= a;
    }
    return a;
}

int main()
{
    cin >> n >>k ;
    for(int i = 1;i <= n; i++)
        cin >> a[i];
    for(int i =1 ;i <= n;i++)
        cin >> b[i];
    quickSort(1,n);
    int c = gcd(a[k],b[k]);
    cout<<a[k]/c<<" "<<b[k]/c;

}

