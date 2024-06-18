#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FILE_IO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define BEGIN auto begin_run = chrono::steady_clock::now();

#define END auto end_run = chrono::steady_clock::now();\
auto time_run = end_run - begin_run;\
cout << "\nTime: " << chrono::duration_cast<chrono::milliseconds>(time_run).count() << " ms.";

long long n, a[100005];
long long ans = 0;
string s, line;

void XuLy()
{
    cin >> n;
    getline(cin, line);
    for (int i = 1; i <= n; i++)
    {
        getline(cin, s);
        int tmp = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
            {
                tmp++;
            }
        }
        a[i] = tmp;
    }
    for (int i = 1; i <= n; i++)
    {
        ans += a[i] * (n - i + 1);
    }
    if (n > 0)
        cout << ans + 33 * (n + 1) + 30 + 14 * n + 3 * (n - 1) << '\n';
    else
        cout << 63 << '\n';
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
    
