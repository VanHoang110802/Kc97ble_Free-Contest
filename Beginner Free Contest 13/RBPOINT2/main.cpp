#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
const int oo = 1000000007;

int n;
pair<int, int> p[2*MAXN];

int main() {
    cin >> n;
    for(int i = 0; i < 2*n; ++i) {
        cin >> p[i].first;
        if (i < n)
            p[i].second = 0;
        else
            p[i].second = 1;
    }

    sort(p, p + 2*n);

    int ans = oo;
    for(int i = 1; i < 2*n; ++i)
        if (p[i].second + p[i-1].second == 1)
            ans = min(ans, p[i].first - p[i-1].first);

    cout << ans;

    return 0;
}
