#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long a, b, k;
    cin >> a >> b;
    k = 0;
    while(a <= b){
        k++;
        a *= 3;
        b *= 2;
    }
    cout << k;
    return 0;
}
