#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;

    if (n<0) n=-n;

    n%=1000;

    if (n<10) cout << "00" << n;
    else
    if (n<100) cout << 0 << n;
    else cout << n;
    return 0;
}
