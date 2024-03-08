#include <fstream>
#define MOD 9901

using namespace std;

ifstream cin("cladire1.in");
ofstream cout("cladire1.out");

int mb[1005][1005], dp[1005][1005];

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++) {
		int x, y;
		cin >> x >> y;
		mb[x][y] = 1;
	}
	if(!mb[1][1])
		dp[1][1] = 1;
	mb[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!mb[i][j])
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			dp[i][j] %= MOD;
		}
	}
	cout << dp[n][m];
}