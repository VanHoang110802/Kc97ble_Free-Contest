#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        string s;
        long long k;
        cin >> s >> k;

        bool isPalin = true;
        for(int i = 0, j = s.length()-1; i < j; ++i, --j)
            if (s[i] != s[j])
                isPalin = false;

        puts((isPalin) ? "YES" : "NO");
    }

    return 0;
}
