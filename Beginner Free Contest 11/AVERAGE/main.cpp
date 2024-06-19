#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int maxS = 40005;
int nTest, n, a, x[205], dp[2][2*maxS];

int main()
{
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> nTest;
    while (nTest--)
    {
        cin >> n >> a;
        for(int i = 0; i < n; ++i)
        {
            cin >> x[i];
            x[i] -= a;
        }

        memset(dp, 0, sizeof dp);
        dp[0][maxS] = 1;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < 2*maxS; ++j)
            {
                if (dp[0][j] > 0)
                {
                    dp[1][j] = (dp[1][j] + dp[0][j]) % MOD;
                    if (dp[1][j] >= MOD) dp[1][j] -= MOD;

                    dp[1][j + x[i]] = (dp[1][j + x[i]] + dp[0][j]) % MOD;
                    if (dp[1][j + x[i]] >= MOD) dp[1][j + x[i]] -= MOD;
                }
            }
            for(int j = 0; j < 2* maxS; ++j)
            {
                dp[0][j] = dp[1][j];
                dp[1][j] = 0;
            }
        }

        cout << ((dp[0][maxS]-1+MOD)%MOD) << '\n';
    }

    return 0;
}
