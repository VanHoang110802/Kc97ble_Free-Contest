#include <iostream>
#include <iomanip>
using namespace std;

#define int long long

void XuLy()
{
    int n, a, b;
    cin >> n >> a >> b;
    if (a > b || n < 1) cout << 0;
    else if (n == 1)
    {
        if(a == b) cout << 1;
        else cout << 0;
    }
    else cout << (b - a) * (n - 2) + 1;
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
