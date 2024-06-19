#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;

int n, x[MAXN], y[MAXN];

int main() {
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];

    int ans = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            ans = max(ans, abs(x[i] - x[j]) + abs(y[i] - y[j]));

    cout << ans;

    return 0;
}
