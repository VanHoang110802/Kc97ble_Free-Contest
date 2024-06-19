//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FILE_IO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define BEGIN auto begin_run = chrono::steady_clock::now();

#define END auto end_run = chrono::steady_clock::now();\
auto time_run = end_run - begin_run;\
cout << "\nTime: " << chrono::duration_cast<chrono::milliseconds>(time_run).count() << " ms.";

long long a[1005], cnt[2][55], f[55], k[55];
long long n, m;

void XuLy()
{
    cin >> n >> m;
    f[0] = 1;
    for(int i = 1; i <= 50; ++i) f[i] = f[i - 1] * 2;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        for(int j = 0; j <= 50; ++j) cnt[(a[i] >> j) & 1][j]++;
    }
    long long res = 0;
    for(int i = 0; i <= 50; ++i)
    {
        long long tmp = min(cnt[0][i], cnt[1][i]);
        if (cnt[0][i] < cnt[1][i]) k[i] = 1;
        else k[i] = 0;
        res += tmp * f[i];
    }
    if (res > m)
    {
        cout << -1;
        return;
    }
    long long K = 0;
    for(int i = 0; i <= 50; ++i)
    {
        if (k[i] == 1)
            K += f[i];
    }
    for (int i = 50; i >= 0; i--)
    {
        if (k[i] == 0)
        {
            K += f[i];
            res = 0;
            for(int j = 1; j <= n; ++j)
            {
                res += (K ^ a[j]);
            }
            if (res > m)
                K -= f[i];
        }
    }
    cout << K;
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
    
