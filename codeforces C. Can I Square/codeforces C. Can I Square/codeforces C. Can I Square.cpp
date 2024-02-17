#include <iostream>
#include <cmath>
#define int long long

using namespace std;

signed main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int sp = 0;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			sp += x;
		}
		if (sqrt(sp) == (int)sqrt(sp))
			cout << "YES\n";
		else cout << "NO\n";
	}
}