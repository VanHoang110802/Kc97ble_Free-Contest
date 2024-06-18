#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;

int nTest, n, k, a[MAXN];

int main() {
    scanf("%d", &nTest);
    while (nTest--) {
        scanf("%d%d", &n, &k);
        for(int i = 0; i < n; ++i)
            scanf("%d", &a[i]);

        int maxA = 0;
        for(int i = 0; i < n; ++i)
            maxA = max(maxA, a[i]);

        int sumA = 0;
        for(int i = 0; i < n; ++i)
            sumA += maxA - a[i];

        if (k >= sumA && (k - sumA)%n == 0)
            puts("YES");
        else
            puts("NO");
    }

    return 0;
}
