#include <iostream>
#define int long long

using namespace std;

signed main() {
	int n, t, b, a;
	cin >> n >> t >> b >> a;
	int ci = t / b;
	int r = (t % b) / a, ans = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (ci >= n - i + 1)
			r = 0;
		if (r)
			r--;
		else ans += x, ci--;
		if (!ci)
			break;
	}
	cout << ans;
}