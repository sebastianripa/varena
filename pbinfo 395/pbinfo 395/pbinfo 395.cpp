#include <fstream>

using namespace std;

ifstream cin("comori.in");
ofstream cout("comori.out");

int a[205][205], dp[205][205];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			if (i == 1)
				dp[i][j] = a[i][j];
		}
	}
	int ans = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i - 1][j + 1])) + a[i][j];
			if (i == n)
				ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
}