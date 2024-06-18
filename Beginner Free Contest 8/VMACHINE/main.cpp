#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int64_t n;
        cin >> n;
        vector<int64_t> ans;
        for (int64_t i = 1; i <= n; i *= 2) {
            ans.push_back(i);
        }
        cout << ans.size() << '\n';
        for (int64_t i: ans) cout << i << ' ';
        cout << '\n';
    }
}
