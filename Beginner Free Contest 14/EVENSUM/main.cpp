#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    int n; cin>>n;
    long long res=0;
    for (int i=1; i <= n; i++){
        int x; cin>>x;
        if (i%2 == 0){
            res+=x;
        }
    }
    cout<<res;
    return 0;
}
