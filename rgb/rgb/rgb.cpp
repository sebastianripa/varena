#include <iostream>
#define int long long

using namespace std;

signed main() {
	int n, m;
	cin >> n >> m;
	int r, g, b;
	cin >> r >> g >> b;
	if (b == 0) {
		if (abs(r - g) > 1)
			cout << "NO", exit(0);
		cout << "YES" << '\n';
		bool st = 1;
		if (g > r)
			st = 0;
		bool ok;
		for (int i = 1; i <= n; i++) {
			ok = st;
			if (i % 2)
				ok = !ok;
			for (int j = 1; j <= m; j++) {
				if (!ok)
					cout << "R";
				else cout << "G";
				ok = !ok;
			}
			cout << '\n';
		}
	}
	else if (n == 1) {
		if (max(r, max(g, b)) == r && b + g < r)
			cout << "NO", exit(0);
		if (max(r, max(g, b)) == g && b + r < g)
			cout << "NO", exit(0);
		if (max(r, max(g, b)) == b && r + g < b)
			cout << "NO", exit(0);
		cout << "YES" << '\n';
		if(b > )
		while (b && g) {
			cout << "BG";
			b--;
			g--;
		}
		while (b && r) {
			cout << "BR";
			b--;
			r--;
		}
		while (r && g) {
			cout << "GR";
			r--;
			g--;
		}
	}
	return 0;
}