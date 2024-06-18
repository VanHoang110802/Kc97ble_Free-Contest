#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

#define int long long
const int MAXN = 1e6 + 7;
int a[MAXN], prefix[MAXN];

void XuLy()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
    }
    int MIN = 1e18;
    for(int i = 1; i <= n; ++i)
    {
        MIN = min(MIN, abs(prefix[n] - (prefix[i] + prefix[i])));
    }
    cout << MIN << '\n';
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
