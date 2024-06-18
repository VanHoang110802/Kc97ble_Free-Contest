#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000005
#define HPKLcute ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
ll n,a[nmax];
int main()
{   HPKLcute;
    ll x = 1;
    ll y = 0;
    cin>>n;
    for(ll i = 1; i <= n; i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(ll i = 1; i <= n; i++)
    {
        if(a[i]==a[i+1])
           x++;
        else
        {
            if(a[i]>0)
            {
                y += x*(x-1)*(x-2)/6;
            }
            x=1;
        }
    }
    cout<<y;
}
    
