#include <iostream>
#include <set>

using namespace std;

int v[10005];
set <int> vr;

int main() {
	int n, r;
	cin >> n >> r;
	for (int i = 1; i <= r; i++) {
		int x, y;
		cin >> x >> y;
		v[x] = max(v[x], y);
		vr.insert(x);
	}
	int ans = 0;
	for (auto x : vr) {
		if (x > 2) {
			if (!v[x - 2] && !v[x - 1] && !v[x + 1] && !v[x + 2]) {
				ans += v[x];
				continue;
			}
		}
		else if (x > 1) {
			if (!v[x - 1] && !v[x + 1] && !v[x + 2]) {
				ans += v[x];
				continue;
			}
		}
		else {
			if (!v[x + 1] && !v[x + 2]) {
				ans += v[x];
				continue;
			}
		}
	}
	cout << ans;
}