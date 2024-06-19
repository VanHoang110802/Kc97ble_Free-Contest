#include <iostream>
#include <algorithm>
#include <iomanip>
#define llong long long

using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n, m;
bool visited[1006][1006];

void DFS(int x, int y) {
    visited[x][y] = true;

    for(int i = 0; i < 4; ++i) {
        int u = x + dx[i], v = y + dy[i];
        if (1 <= u && u <= n && 1 <= v && v <= m && !visited[u][v]) DFS(u, v);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j) {
        int a; cin >> a;
        visited[i][j] = a == 0;
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j)
    if (!visited[i][j]) ++ans, DFS(i, j);

    cout << ans;

    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
int n,m,d,a[1005][1005];
int main()
{
   // freopen("HCN.inp","r",stdin);
 //   freopen("HCN.out","w",stdout);
    cin>>n>>m;;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        cin>>a[i][j];
        if(a[i][j]==1)
            if(a[i-1][j]==0&&a[i][j-1]==0)d++;
    }
    cout<<d;
}


*/
