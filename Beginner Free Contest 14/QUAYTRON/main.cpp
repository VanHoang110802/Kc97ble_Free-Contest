/*
import math
def sqr(x):
    return x*x;
r,x1,y1,x2,y2 = input().split()
d = math.sqrt(sqr(int(x1)-int(x2))+sqr(int(y1)-int(y2)))
print(math.ceil(d/(2*int(r))))

*/
#include<bits/stdc++.h>
using namespace std;

double s,n,a,b,c,d,t;

int main()
{
    cin>>n>>a>>b>>c>>d;n=n*2;
    s=(c-a)*(c-a)+(d-b)*(d-b);
    s=sqrt(s);
    t=s/n;
    if(int(t)==t) cout<<t;
    else cout<<int(t)+1;
}
