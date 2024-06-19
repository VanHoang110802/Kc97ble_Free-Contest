#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000005
#define fi first
#define se second
#define bit(x,i) ((x >> i) & 1)
const ll mod = 1e9+7;
const ll base = 31;

ll power(ll a,ll n, ll mod)
{
    if(n == 0)
       return 1;
    else
    {
        ll temp = power(a,n/2,mod) % mod;
        temp = (temp * temp) % mod;
        if(n%2 == 1)
           return (a * temp) % mod;
        else
           return temp;
    }
}

string A,B;
ll m,a,b,f[nmax],ans = 1;
void solve()
{
    cin>>A>>B>>m;
    for(int i = 0; i < A.size(); i++)
       a = (a*10 + A[i] - '0') % m;
    f[0] = a;
    for(int i = 1; i < B.size(); i++)
        f[i] = power(f[i-1],10,m);
    for(int i = 0; i < B.size(); i++)
    {
        ans *= power(f[i],B[B.size() - i - 1] - '0',m);
        ans %= m;
    }
    cout<<ans;
}
int main()
{
    
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
   
    solve();
   
}
    
