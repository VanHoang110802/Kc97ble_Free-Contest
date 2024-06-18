#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

#define int long long
const int MAXN = 1e6 + 7;
int a[MAXN];

void XuLy()
{
    int n;
    cin >> n;
    int MIN = 0, MAX = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        MIN = min(MIN, a[i]);
        MAX = max(MAX, a[i]);
    }
    cout << (MAX - MIN) * 2 << '\n';
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
