#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<bool> freeRow(n, true), freeCol(m, true);

    for(int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        freeRow[x-1] = false;
        freeCol[y-1] = false;
    }

    int remainRow = 0, remainCol = 0;
    for(int i = 0; i < n; ++i)
        if (!freeRow[i])
            ++remainRow;
    for(int i = 0; i < m; ++i)
        if (!freeCol[i])
            ++remainCol;

    long long ans = 1LL * remainRow * remainCol;
    cout << ans;

    return 0;
}
