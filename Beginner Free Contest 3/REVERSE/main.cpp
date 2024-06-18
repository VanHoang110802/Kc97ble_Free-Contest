#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

#define int long long
const int MAXN = 1e6 + 7;
int cnt[MAXN];

void XuLy()
{
    string s;
    int T;
    cin >> s >> T;
    s = ' ' + s;
    int n = s.size();
    while (T--)
    {
        int x;
        cin >> x;
        cnt[x]++;
        cnt[n - x + 2]--;
    }
    for (int i = 1; i <= n; ++i)
    {
        cnt[i] += cnt[i - 1];
    }
    for (int i = 1; i <= n / 2; ++i)
    {
        if (cnt[i] & 1)
        {
            swap(s[i], s[n - i]);
        }
    }
    for(int i = 1; i < s.size(); ++i) cout << s[i];
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
