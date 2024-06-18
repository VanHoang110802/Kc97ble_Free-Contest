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
    for(int i = 1; i <= n; ++i) cin >> a[i];
    if(a[1] >= 2)
    {
        cout << "NO\n";
        return 0;
    }
    for(int i = 1; i <= n; ++i)
    {
        int tmpA = a[i], tmpN = i;
        for(int j = 2; j * j <= i; ++j)
        {
            while(tmpN % j == 0)
            {
                tmpA/=a[j];
                tmpN/=j;
            }
        }
        if (a[tmpN] != tmpA)
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
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
