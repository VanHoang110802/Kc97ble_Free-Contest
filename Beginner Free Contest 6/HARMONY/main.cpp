#include <bits/stdc++.h>
using namespace std;

int T,n,a[1005];

int main() 
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int maxlen=1,Count=1;
		for(int i=2;i<=n;i++)
			if(abs(a[i]-a[i-1])==1)
				Count++;
			else
			{
				maxlen=max(maxlen,Count);
				Count=1;
			}
		maxlen=max(maxlen,Count);
		cout<<(maxlen>n/2?"Yes":"No")<<"\n";
	}
}
