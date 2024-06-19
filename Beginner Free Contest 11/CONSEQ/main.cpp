#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FILE_IO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define BEGIN auto begin_run = chrono::steady_clock::now();

#define END auto end_run = chrono::steady_clock::now();\
auto time_run = end_run - begin_run;\
cout << "\nTime: " << chrono::duration_cast<chrono::milliseconds>(time_run).count() << " ms.";

int a[100005];
int n, x, l, r, dem = 0;
map<int, int> f;

void XuLy()
{
    cin >> n;
    for(int i = 1; i<= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i)
    {
        l = a[i];
        r = a[i];
        for(int j = i; j <= n; ++j)
        {
            f[a[j]]++;
            l = min(l, a[j]);
            r = max(r, a[j]);
            if (f[a[j]] == 1)
            {
                if (r - l == j - i) dem++;
            }
            else
            {
                x = j;
                break;
            }
            x = n;
        }
        for(int j = i; j <= x; ++j) f[a[j]] = 0;
    }
    cout << dem;
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
    
