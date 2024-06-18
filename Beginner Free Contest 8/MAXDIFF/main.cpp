#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    int ans = 0;
    for(int i = 0; i < n; ++i) {
        vector<int> b = a;
        b.erase(b.begin() + i);

        int beauty = 0;
        for(int j = 1; j < b.size(); ++j)
            beauty = max(beauty, b[j] - b[j-1]);
        ans = max(ans, beauty);
    }

    cout << ans;

    return 0;
}
