#include <iostream>
#include <climits>

using namespace std;

int m[405][405], sp[405][405];

int32_t main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> m[i][j];
			sp[i][j] = sp[i - 1][j] + m[i][j];
		}
	}
	int ans = INT_MIN;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			int aux[405];
			for (int k = 1; k <= n; k++)
				aux[k] = sp[j][k] - sp[i - 1][k];
			int s = 0;
			for (int i = 1; i <= n; i++) {
				s += aux[i];
				ans = max(s, ans);
				if (s < 0)
					s = 0;
			}
		}
	}
	cout << ans;
}