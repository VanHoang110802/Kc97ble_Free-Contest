#include <bits/stdc++.h>
using namespace std;

void Input(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

void Solve(){
	int a, b, x, y; cin >> a >> b >> x >> y;
	cout << a * x + b * y;
}

int main(){
	Input();
	Solve();
	return 0;
}
