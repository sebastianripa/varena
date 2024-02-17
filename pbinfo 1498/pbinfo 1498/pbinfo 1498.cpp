#include <fstream>
#include <climits>
#define int long long

using namespace std;

ifstream cin("ciocolata.in");
ofstream cout("ciocolata.out");

int sp[605][605];

int32_t main() {
	int n, m1;
	cin >> n >> m1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m1; j++) {
			int x;
			cin >> x;
			sp[i][j] = sp[i - 1][j] + x;
		}
	}
	int ans = INT_MIN, rs = 1, cs = 1, rj = 1, cj = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= m1; j++) {
			int aux[505];
			for (int k = 1; k <= m1; k++)
				aux[k] = sp[j][k] - sp[i - 1][k];
			int s = 0, l = 1;
			for (int k = 1; k <= m1; k++) {
				s += aux[k];
				if (ans < s) {
					rs = i;
					cs = l;
					rj = j;
					cj = k;
					ans = s;
				}
				if (s < 0)
					s = 0, l = k + 1;
			}
		}
	}
	cout << ans << '\n';
	cout << rs << ' ' << cs << ' ' << rs << ' ' << cj << '\n' << rj << ' ' << cs << ' ' << rj << ' ' << cj;
}