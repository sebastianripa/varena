#include <fstream>

using namespace std;

ifstream cin("gradina.in");
ofstream cout("gradina.out");

bool m[1005][1005];
int sp[1005][1005];

int main() {
	int n, p, k;
	cin >> n >> p >> k;
	for (int i = 1; i <= p; i++) {
		int x, y;
		cin >> x >> y;
		m[x][y] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			sp[i][j] = sp[i - 1][j] + m[i][j];
	}
	int ans = 0, nrm = 0;
	for (int i = 1; i <= n - k + 1; i++) {
		int aux[1005];
		for (int j = 1; j <= n; j++)
			aux[j] = sp[i + k - 1][j] - sp[i - 1][j];
		int s = 0;
		for (int j = 1; j <= k; j++)
			s += aux[j];
		for (int j = k + 1; j <= n; j++) {
			if (ans < s)
				ans = s, nrm = 1;
			else if (ans == s) nrm++;
			s -= aux[j - k];
			s += aux[j];
		}
		if (ans < s)
			ans = s, nrm = 1;
		else if (ans == s) nrm++;
	}
	cout << ans << '\n' << nrm;
}