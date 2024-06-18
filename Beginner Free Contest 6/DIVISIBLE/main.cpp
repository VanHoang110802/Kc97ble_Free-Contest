#include <bits/stdc++.h>
using namespace std;

int64_t T,l,r;

int64_t Cal(int64_t x)
{
	if(x==-1)
		return 0;
	return x/4+x/7+x/11-x/28-x/44-x/77+x/308+1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>l>>r;
		cout<<Cal(r)-Cal(l-1)<<"\n";
	}
}
