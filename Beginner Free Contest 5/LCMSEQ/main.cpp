#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FILE_IO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define BEGIN auto begin_run = chrono::steady_clock::now();

#define END auto end_run = chrono::steady_clock::now();\
auto time_run = end_run - begin_run;\
cout << "\nTime: " << chrono::duration_cast<chrono::milliseconds>(time_run).count() << " ms.";

int nt[360], pc[360];
unsigned long long f[360][360];
int n, k;

unsigned long long __lcm(unsigned long long a, unsigned long long b)
{
    return a / __gcd(a, b) * b;
}

void XuLy()
{
    cin >> n;
    memset(nt, true, sizeof(nt));
    nt[1] = false;
    for(int i = 2; i <= n; ++i)
    {
        if(nt[i])
        {
            for(int j = 2; j <= n / i; ++j)
            {
                nt[i * j] = false;
            }
        }
    }
    k = 0;
    for(int i = 1; i <= n; ++i)
    {
        if (nt[i])
        {
            pc[++k] = i;
        }
    }
    for(int i = 0; i <= n; ++i)
    {
        for(int j = 0; j <= k; ++j)
        {
            f[i][j] = 1;
        }
    }

    for(int j = 1; j <= k; ++j)
    {
        for(int i = 1; i <= n; ++i)
        {
            f[i][j] = f[i][j - 1];
            unsigned long long x = 1;
            while (x <= i)
            {
                f[i][j] = max(f[i][j], __lcm(f[i - x][j - 1], x));
                x *= pc[j];
            }
        }
    }
    cout << f[n][k];
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
    
