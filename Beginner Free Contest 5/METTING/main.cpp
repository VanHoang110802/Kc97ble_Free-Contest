#include <chrono>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

#define int long long
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FILE_IO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define BEGIN auto begin_run = chrono::steady_clock::now();

#define END auto end_run = chrono::steady_clock::now();\
auto time_run = end_run - begin_run;\
cout << "\nTime: " << chrono::duration_cast<chrono::milliseconds>(time_run).count() << " ms.";

//const int MAXN = (int)1e6 + 7;
//int a[MAXN], b[MAXN];
string t;
int n;

void XuLy()
{
    cin >> n >> t;
    for(int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        int y = 0;
        int x = (int)s.size();
        for(int i = 0; i < x; i++)
        {
            if(s[i]==t[0])
            {
                y = 1;
                break;
            }
        }
        if(y == 0) cout << s << '\n';
    }
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
    
