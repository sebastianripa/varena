#include <iostream>
#define int long long

using namespace std;

int a[100005], b[100005], a1[10005][10005];

signed main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++)
		cin >> b[i];
	int ans = 0;
	if (n == 1) {
		for (int i = 1; i <= m; i++) {
			if (b[i] * a[1] > b[i - 1] * a[1] && b[i] * a[1] > b[i + 1] * a[1])
				ans++;
		}
		cout << ans;
		exit(0);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			a1[i][j] = a[i] * b[j];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a1[i][j] > a1[i - 1][j] && a1[i][j] > a1[i][j - 1] && a1[i][j] > a1[i + 1][j] && a1[i][j] > a1[i][j + 1])
				ans++;
		}
	}
	cout << ans;
}