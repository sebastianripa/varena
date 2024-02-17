#include <iostream>
#include <set>
#define MOD 1000000007

using namespace std;

int v[200005];

int main() {
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	while (q--) {
		int l, r, k;
		cin >> l >> r >> k;
		bool ok = 0;
		if (r - l + 1 == k)
			ok = 1;
		multiset <int> s;
		long long p = 1;
		for (int i = l; i <= r; i++) {
			if (ok)
				p *= v[i], p %= MOD;
			else
				s.insert(-v[i]);
		}
		if (!ok) {
			for (auto x : s) {
				p *= (-x);
				p = p % MOD;
				k--;
				if (k == 0)
					break;
			}
		}
		cout << p << '\n';
	}
}