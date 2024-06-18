#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FILE_IO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define BEGIN auto begin_run = chrono::steady_clock::now();

#define END auto end_run = chrono::steady_clock::now();\
auto time_run = end_run - begin_run;\
cout << "\nTime: " << chrono::duration_cast<chrono::milliseconds>(time_run).count() << " ms.";

int a[1005];
int n, hmin, hmax, wmin, wmax, p = 31623, ans, t;

bool check(int t)
{
    if (t == 0)
        return 0;
    if (hmax / t * t >= hmin && wmax / t * t >= wmin)
        return true;
    return false;
}

void XuLy()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> hmin >> hmax >> wmin >> wmax;
        ans = 1;
        for (int j = 1; j <= p; j++)
            if (check(j))
                ans = j;
        for (int j = 1; j <= p; j++)
        {
            t = hmax / j;
            if (check(t))
                ans = max(ans, t);
        }
        for (int j = 1; j <= p; j++)
        {
            t = wmax / j;
            if (check(t))
                ans = max(ans, t);
        }
        cout << ans << '\n';
    }
}

int main()
{
    //BEGIN;
    //FILE_IO;
    FAST_IO;
    //int test; cin >> test; while(test--)
    {
        XuLy();
    }
    //END;
    return 0;
}
    
