#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define st first
#define nd second
using namespace std;

const long long INF = 1e18;
const long long N = 2e5 + 5;
int n, a[N];
int sp[20][N];
map <int, int> L, R;
set <int> d;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen(file".inp", "r", stdin); freopen(file".out", "w", stdout);
    #endif
    
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        if (a[i])
            d.insert(a[i]);
    }

    for (int i = 1; i <= n; i ++)
        R[a[i]] = i;

    for (int i = n; i >= 1; i --)
        L[a[i]] = i;

    for (int i = 1; i <= n; i ++)
        if (i == L[a[i]])
            sp[0][i] = R[a[i]];
        
    for (int i = 1; (1 << i) <= n; i ++)
        for (int j = 1; j + (1 << i) - 1 <= n; j ++)
            sp[i][j] = max(sp[i - 1][j], sp[i - 1][j + (1 << i - 1)]);

    auto get = [&] (int l, int r) {
        if (l > r) return 0;
        int k = log2(r - l + 1);
        return max(sp[k][l], sp[k][r - (1 << k) + 1]);
    };

    set <pii> vi;
    for (int i: d) {
        vi.insert({L[i], R[i]});
    
        if (get(L[i] + 1, R[i] - 1) > R[i]) {
            cout << -1 << '\n';
            return 0;
        }

    }
    int ans = 0;

    while (vi.size()) {
        pii p = *vi.begin();
        vector <pii> save;
        while (true) {
            save.push_back(p);
            auto it = vi.lower_bound({p.nd + 1, 0});
            if (it == vi.end()) break;
            
            p = *it;
        }

        for (pii x: save)
            vi.erase(x);

        ans ++;

        // cout << ans << endl;
    }

    cout << ans << '\n';

    return 0;
}  
