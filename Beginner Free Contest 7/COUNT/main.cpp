#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int n; cin >> n;
	vector < long long > a(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] += a[i - 1];
	}
	long long answer = 0;
	if (a[n] % 3 == 0) {
		vector <int> cnt(n + 2, 0);
		for (int i = n - 1; i > 0; --i) {
			cnt[i] = cnt[i + 1] + (a[n] - a[i] == a[n] / 3);
		}
		for (int i = 1; i <= n; ++i) if (a[i] == a[n] / 3) answer += cnt[i + 1];
	}
	cout << answer << "\n";
 
	return 0;
}
