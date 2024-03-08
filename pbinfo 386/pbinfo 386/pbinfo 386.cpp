#include <fstream>

using namespace std;

ifstream cin("sumtri1.in");
ofstream cout("sumtri1.out");

int m[105][105], dp[105][105], mr[105][105], v[105];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++)
			cin >> m[i][j];
	}
	dp[1][1] = m[1][1];
	int ans = 21e8, pz = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1)
				dp[i][j] = dp[i - 1][j] + m[i][j], mr[i][j] = 0;
			else if (j == i)
				dp[i][j] = dp[i - 1][j - 1] + m[i][j], mr[i][j] = 1;
			else {
				if (dp[i - 1][j] > dp[i - 1][j - 1])
					dp[i][j] = dp[i - 1][j - 1] + m[i][j], mr[i][j] = 1;
				else dp[i][j] = dp[i - 1][j] + m[i][j], mr[i][j] = 0;
			}
			if (i == n && ans > dp[i][j])
				ans = dp[i][j], pz = j;
		}
	}
	cout << ans << '\n';
	int i = n;
	while (i) {
		v[i] = m[i][pz];
		pz -= mr[i][pz];
		i--;
	}
	for (int i = 1; i <= n; i++)
		cout << v[i] << ' ';
}