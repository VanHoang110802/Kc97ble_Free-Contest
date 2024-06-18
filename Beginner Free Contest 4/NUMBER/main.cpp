#include <chrono>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

#define int long long
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FILE_IO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define BEGIN auto begin_run = chrono::steady_clock::now();

#define END auto end_run = chrono::steady_clock::now();\
auto time_run = end_run - begin_run;\
cout << "\nTime: " << chrono::duration_cast<chrono::milliseconds>(time_run).count() << " ms.";

const int MAXN = (int)1e6 + 7;
int a[MAXN];

void XuLy()
{
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(a[i] != 0 && a[i - 1] != 0)
        {
            ans++;
            a[i]--;
        }
        ans += (a[i] / 2);
        a[i] %= 2;
    }
    cout << ans;
}

int32_t main()
{
    BEGIN;
    FILE_IO;
    FAST_IO;
    //int test; cin >> test; while(test--)
    {
        XuLy();
    }
    END;
    return 0;
}
