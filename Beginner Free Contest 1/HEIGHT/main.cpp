#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
using namespace std;

#define int long long
const int MAXN = 1e6 + 7;
int test;
int a[MAXN], b[MAXN];

void XuLy()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
    {
        int it = lower_bound(a + 1, a + n + 1, b[i]) - a - 1;
        cout << it << ' ';
    }
    cout << '\n';
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
