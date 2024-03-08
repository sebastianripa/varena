#include <iostream>

using namespace std;

int v[200005];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> v[i];
		int nrinvdupa = 0;
		for (int i = 2; i <= n; i++) {
			if (v[i] <= v[i - 1])
				nrinvdupa++;
		}
		int ans = n, nrinvinainte = 0;
		for (int i = 1; i <= n; i++) {
			bool inmultitNegativ = 0;
			if (i > 1)
				inmultitNegativ = 1;
			ans = min(ans, inmultitNegativ + nrinvdupa + nrinvinainte);
			if (i < n && v[i] >= v[i + 1])
				nrinvdupa--;
			if (i > 1 && v[i - 1] <= v[i])
				nrinvinainte++;
		}
		cout << ans << '\n';
	}
}