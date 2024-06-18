#include <bits/stdc++.h>
using namespace std;

int n,a[8005];
int64_t res=0;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		int p=i;
		for(int j=1;j<i;j++)
		{
			while(p<n&&a[j]+a[i]>a[p+1])
				p++;
			res+=p-i;
		}
	}
	cout<<res;
}
