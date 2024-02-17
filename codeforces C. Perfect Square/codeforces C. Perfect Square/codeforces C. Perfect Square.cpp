#include <iostream>

using namespace std;

char m[1005][1005];

int dif(char c1, char c2) {
	int n1 = c1, n2 = c2;
	if (n2 > n1) {
		int aux = 122 - n2;
		return aux + (n1 - 97) + 1;
	}
	else
		return n1 - n2;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				cin >> m[i][j];
		}
		int ans = 0;
		for (int i = 1; i <= n / 2; i++) {
			for (int j = 1; j <= n / 2; j++) {
				int a = m[i][j], b = m[j][n - i + 1], c = m[n - j + 1][i], d = m[n - i + 1][n - j + 1];
				int mx = max(max(a, b), max(c, d));
				int cnt = mx * 4 - a - b - c - d;
				ans += cnt;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}