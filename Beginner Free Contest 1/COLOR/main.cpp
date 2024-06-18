#include <bits/stdc++.h>
using namespace std;
const int64_t MOD = 1e9 + 7;
int64_t q;
int64_t fac1 = 1, fac2 = 1;

int64_t Pmod (int64_t x, int64_t y) {
        if (y == 0) return 1;
        int64_t temp = Pmod(x, y / 2) % MOD;
        if (y % 2 == 0) return (temp * temp) %MOD;
        return ((temp * temp) % MOD * x) % MOD;
}

void solve() {
    int64_t n, k;
    cin >> n >> k;
    if (n < 0) {
        cout << 0;
        return;
    }    
    for (int i = 1; i <= k; i++) {
        fac2 = (fac2 * i) % MOD;
    }  
    for (int i = n - k + 1; i > n - 2 * k + 1; i--) fac1 = (fac1 * i) % MOD;
    // (n - k + 1) C (k)
    cout << ((fac1 * Pmod(fac2, MOD - 2)) % MOD);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
}
// n - k + 1 - n + 2 * k + 1 = k;
// chia n - 2 * k + 1 keo cho k + 1 thang
// n - 2 * k + 1 + k + 1 - 1 = n - k + 1; 
// n! / (n - r)!r!
// n! * (n - r)! ^ (P - 2) * r! ^ (P - 2) mod P;
// chia keo
int main () {
    ios_base :: sync_with_stdio(false);
    //cin >> q;
    q = 1;
    while (q--) {
        solve();
    }
}

/*
#include<bits/stdc++.h>
#define el cout<<"\n"
#define f0(i,n) for(int i=0;i<n;++i)
#define f1(i,n) for(int i=1;i<=n;++i)
#define maxn
#define MOD 1000000007
using namespace std;
int n, k;
long long Pow(long long a, int n)
{
    if (n == 1) return a;
    long long t = Pow(a, n/2);
    t = t*t%MOD;
    if (n%2) t = t*a%MOD;
    return t;
}
long long inv(int n)
{
    return Pow(n, MOD-2);
}
long long C(int n, int k)
{
    if (n < k) return 0;
    long long ans = 1;
    for (int i=n; i>n-k; i--) ans = ans * i % MOD;
    for (int i=1; i<=k; i++) ans = ans * inv(i) % MOD;
    return ans;
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    cout << C (n-k+1, k);
}

*/
