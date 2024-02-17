#include <iostream>

using namespace std;

//ifstream cin("buldo.in");
//ofstream cout("buldo.out");

int v[100005];

int main() {
	int mx = 0, mn = 21e8, n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		mx = max(mx, v[i]);
		mn = min(mn, v[i]);
	}
	int mid, ans = 0;
	int l = mn, r = mx;
	while (l < r) {
		mid = (r + l) / 2;
		int s = 0, i;
		for (i = 1; i <= n; i++) {
			s += v[i] - mid;
			if (s < 0)
				break;
		}
		if (i == n + 1) {
			l = mid + 1;
			ans = mid;
			continue;
		}
		r = mid;
	}
	cout << ans;
}