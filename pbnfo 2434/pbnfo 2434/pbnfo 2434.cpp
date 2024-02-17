#include <iostream>
#include <vector>

using namespace std;

vector <int> v;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	int q;
	cin >> q;
	while (q--) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		int ans = 0;
		int dr = lower_bound(v.begin(), v.end(), c2) - v.begin();
		int st = upper_bound(v.begin(), v.end(), c1) - v.begin();
		ans += dr - st + 1;
		ans *= (r2 - r1 + 1);
		cout << ans << '\n';
	}
}