#include <bits/stdc++.h>
#define ll long long
#define nmax 100005
#define fo(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int base=37;
const int mod=1e9+7;
ll n,l,r,k,a[nmax],t[nmax],hasha[nmax],poww[nmax];
string s;
ll gett(ll i,ll j)
{
    return (((hasha[j]-hasha[i-1]*poww[j-i+1])%mod)+mod)%mod;
}
int main()
{
    cin>>s;
    n=s.size();
    s=" "+s;
    poww[0]=1;
    fo(i,1,n)
    poww[i]=(poww[i-1]*base)%mod;
    fo(i,1,n)
    hasha[i]=(hasha[i-1]*base+s[i]-'a'+1)%mod;
    fo(i,1,n)
    {
        l=1;r=n-i+1;k=0;
        while(l<=r)
        {
            ll mid=(l+r)/2;
            if(gett(1,mid)==gett(i,i+mid-1))
            {
                k=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        a[1]++;a[k+1]--;
    }
    fo(i,1,n) t[i]=t[i-1]+a[i];
    fo(i,1,n) cout<<t[i]<<' ';
}
   
