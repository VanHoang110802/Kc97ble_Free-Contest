#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
int n, a[MAXN];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    int cntPositive = 0, cntNegative = 0, cntZero = 0;
    for(int i = 0; i < n; ++i) {
        if (a[i] > 0)
            ++cntPositive;
        else if (a[i] < 0)
            ++cntNegative;
        else
            ++cntZero;
    }

    int ans;
    if (cntZero > 0)
        ans = -1;
    else
        ans = min(cntPositive, cntNegative);

    printf("%d\n", ans);

    return 0;
}
