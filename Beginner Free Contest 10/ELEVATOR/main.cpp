#include <chrono>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
using namespace std;

#define int long long
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FILE_IO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define BEGIN auto begin_run = chrono::steady_clock::now();

#define END auto end_run = chrono::steady_clock::now();\
auto time_run = end_run - begin_run;\
cout << "\nTime: " << chrono::duration_cast<chrono::milliseconds>(time_run).count() << " ms.";

const int MAXN = (int)1e6 + 7;
int a[MAXN];
int n, k, s;

void XuLy()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, greater<int>());
    for(int i = 0; i < n; i += k) s += (a[i] - 1) * 2;
    cout << s;
}

int32_t main()
{
    //BEGIN;
    //FILE_IO;
    FAST_IO;
    //int test; cin >> test; while(test--)
    {
        XuLy();
    }
    //END;
    return 0;
}
    
