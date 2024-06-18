#include <bits/stdc++.h>
#define TASKNAME "BTOWER"
#define maxn 1000010
#define cmax 1000000007
#define llmax (1LL << 61)
#define el '\n'
#define pb push_back
#define mp make_pair
#define getbit(s,i) ((s>>(i-1))&1)
#define bug(X) { cerr << #X << " = " << (X) << endl; }
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL)
#define For(i,a,b) for(int i = a; i <= b; i++)
#define Ford(i,a,b) for(int i = a; i >= b; i--)
#define Forv(i,v) for(int i = 0, _v = v.size(); i < _v; i++)

using namespace std;

typedef long long ll;
typedef pair<int, int> ptq;

int n;

template <typename T> inline void read(T &x)
{
    x = 0;
    char c;
    bool p = false;
    while (!isdigit(c = getchar())) if (c == '-') p = true;
    do x = x * 10 + c - 48;
    while (isdigit(c = getchar()));
    if (p) x = -x;
}
template <typename T> void Write(T x)
{
    if (x > 9) Write(x/10);
    putchar(x%10+48);
}
template <typename T> void write(T x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    Write(x);
}

class Brick
{
public:
    int a, b, h;

    friend istream& operator >> (istream& cin, Brick &T)
    {
        read(T.a);
        read(T.b);
        read(T.h);
        //cin >> T.a >> T.b >> T.h;
        return cin;
    }

    bool operator < (const Brick &T)
    {
        return (b < T.b) || (b == T.b && a < T.a);
    }
};
Brick a[maxn];

class dataaa
{
public:
    ll T;
    int pos;
    bool operator >(dataaa A)
    {
        return T>A.T;
    }
    bool operator <(dataaa A)
    {
        return T<A.T;
    }
    dataaa()
    {
        T=0;
        pos=0;
    }
    dataaa(ll T, int pos)
    {
        this->T=T;
        this->pos=pos;
    }
};
dataaa f[maxn];

class BIT
{
public:
    int n;

    dataaa T[maxn];

    BIT(int last = maxn)
    {
        n = last;
    }

    template <typename T> T max(T a, T b)
    {
        return a>b?a:b;
    }

    void update(int u, ll x, int i)
    {
        dataaa d(x, i);
        for( ; u <= n; u += (u&(-u))) T[u] = max(T[u], d);
    }

    dataaa get(int u)
    {
        dataaa res;
        for( ; u > 0; u -= u&(-u)) res = max(res, T[u]);
        return res;
    }
};
BIT t(1000000);
vector <int> v;
int trace[maxn];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    read(n);
    For(i,1,n)
    {
        cin >> a[i];
        v.pb(i);
    }
    sort(v.begin(), v.end(), [](int i, int j)
    {
        return a[i] < a[j];
    });
    for(int id : v)
    {
        f[id] = t.get(a[id].a);
        f[id].T += a[id].h;
        t.update(a[id].b, f[id].T, id);
    }
    dataaa res (0, 0);
    int id = -1;
    For(i,1,n)
    {
        if (res < f[i])
        {
            res = f[i];
            id = i;
        }
    }
    write(res.T);
    vector <int> ans;
    while (id != 0)
    {
        ans.push_back(id);
        id = f[id].pos;
    }
    reverse(ans.begin(), ans.end());
    putchar(' ');
    write(ans.size());
    putchar(el);
    for(int x : ans)
    {
        write(x);
        putchar(' ');
    }
}


/*
/// hhoangcpascal

#include <iostream>
#include <algorithm>
#include <vector>
#define llong long long

using namespace std;

struct Data {
    int a, b, h, id;

    bool operator < (const Data &other) const {
        return b < other.b || (b == other.b && a < other.a);
    }
} D[500006];

pair<llong, int> bit[1000006];
int n, trace[500006];

void update(int p, pair<llong, int> val) {
    for(; p <= 1000000; p += (p & (-p))) bit[p] = max(bit[p], val);
}

pair<llong, int> query(int p) {
    pair<llong, int> Max = {0, 0};
    for(; p > 0; p -= (p & (-p))) Max = max(Max, bit[p]);
    return Max;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        int a, b, h; cin >> a >> b >> h;
        D[i] = {a, b, h, i};
    }

    sort(D + 1, D + n + 1);

    pair<llong, int> ans = {0, 0};
    for(int i = 1; i <= n; ++i) {
        pair<llong, int> best = query(D[i].a);
        best.first += D[i].h; trace[i] = best.second; best.second = i;
        ans = max(ans, best);
        update(D[i].b, best);
    }

    cout << ans.first << ' ';

    vector<int> tmp;

    int p = ans.second;
    while (p != 0) {
        tmp.push_back(D[p].id);
        p = trace[p];
    }

    cout << tmp.size() << '\n';
    reverse(tmp.begin(), tmp.end());
    for(int p: tmp) cout << p << ' ';

    return 0;
}


*/
