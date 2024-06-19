#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int product = a * b;
    if (product > 0)
        cout << 1;
    else if (product < 0)
        cout << -1;
    else
        cout << 0;

    return 0;
}
