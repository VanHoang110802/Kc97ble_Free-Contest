#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int n, q, a[MAXN];
long long b[MAXN];

int main() {
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    int res = 0;
    for(int i = 1; i < n; ++i) {
        b[i] = a[i] - a[i+1];
        res += (b[i] > 0);
    }

    for(int i = 1; i <= q; ++i) {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);

        if (l > 1) {
            res -= (b[l-1] > 0);
            b[l-1] += -x;
            res += (b[l-1] > 0);
        }

        if (r < n) {
            res -= (b[r] > 0);
            b[r] += x;
            res += (b[r] > 0);
        }

        printf("%d\n", res);
    }

    return 0;
}
