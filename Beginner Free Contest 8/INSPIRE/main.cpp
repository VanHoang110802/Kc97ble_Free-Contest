#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#define ld long double
using namespace std;
const ld pi = 4.0*atan(1.0);
int n;
string s;

int toInt(char x)
{
	if ('A'<=x and x<='Z')
		return x-'A';
	else
	if ('a'<=x and x<='z')
		return x-'a';
	else
	if (x==' ')
		return 26;
	else
		return 27;
}

int diff(char x,char y)
{
	int X = toInt(x);
	int Y = toInt(y);
	return min(abs(X-Y),28-abs(X-Y));
}

int main()
{
	ios_base::sync_with_stdio(0);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> n;
	getline(cin,s);
	for (int i=1; i<=n; i++)
	{
		getline(cin,s);
		//cout << s << '\n';
		int res = 0;
		
		for (int i=1; i<s.size(); i++)
			res+=diff(s[i],s[i-1]);
		
		ld res2 = s.size();
		cout << setprecision(4) << fixed << res2+(ld) res*pi/7.0 << '\n';
	}
	
	return 0;
}
