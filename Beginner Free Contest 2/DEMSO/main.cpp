#include <iostream>
#include <iomanip>
using namespace std;

#define int long long
const int MAXN = 1e6 + 7;
int a[MAXN], prefix[MAXN];

void XuLy()
{
    int n;
    cin >> n;
    int cnt_1 = 0, cnt_2 = 0;
    for(int i = 1; i <= n; ++i)
    {
        string x;
        cin >> x;
        if((x[0] - '0') > 0) cnt_1++;
        else if((x[0] - '0') < 0) cnt_2++;
    }
    cout << cnt_2 << ' ' << cnt_1 << '\n';
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
