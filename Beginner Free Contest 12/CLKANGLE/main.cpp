#include <iostream>
#include <cstdio>
#include <iomanip>
#define ld long double
using namespace std;

int h,m;

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> h >> m;
	ld angle = abs(0.5*(60.0*h-11.0*m));
	angle = min(angle,360.0-angle);
	cout << setprecision(1) << fixed << angle; 
	return 0;
}
