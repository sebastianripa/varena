#include <iostream>

using namespace std;

int v[100005], vf[100005];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, maxi = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
			vf[i] = 0, v[i] = 0;
		bool ok = 0;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			if (!vf[x])
				vf[x] = i;
			else {
				if (i - vf[x] - 1 < 2)
					v[x] = 1, ok = 1, maxi = max(maxi, x);
				vf[x] = i;
			}
		}
		if (!ok)
			cout << -1;
		else {
			for (int i = 1; i <= n; i++) {
				if (v[i]) {
					if (i != maxi)
						cout << i << ' ';
					else
						cout << i;
				}
			}
		}
		if (t)
			cout << '\n';
	}
}