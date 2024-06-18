#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
using namespace std;

#define int long long
const int MAXN = 1e6 + 7;
int a[MAXN];

void XuLy()
{
    int n, k, ans = 0;
    cin >> n >> k;
    map<int, int> MAP;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        MAP[a[i]]++;
        int x = k - (a[i] * a[i]);
        if(MAP.find(x) != MAP.end()) ans += MAP[x];
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
