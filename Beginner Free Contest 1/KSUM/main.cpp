#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
using namespace std;

#define int long long
const int MAXN = 1e6 + 7;
int a[MAXN], prefix[MAXN], tg[MAXN];
int test;

void XuLy()
{
    int n, k, ans = -1e18;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
    }
    for(int i = 1; i < n; ++i)
    {
        ans = max(ans, prefix[k + i - 1] - prefix[i - 1]);
    }
    cout << ans << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    XuLy();
    cout << "\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.\n";
    return 0;
}
