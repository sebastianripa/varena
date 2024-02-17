#include <fstream>
#define int long long

using namespace std;

ifstream cin("cetate.in");
ofstream cout("cetate.out");

int m[405][405], sp[405][405];

int32_t main() {
	int cer, n, m1, k1;
	cin >> cer >> n >> m1 >> k1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m1; j++) {
			cin >> m[i][j];
			sp[i][j] = sp[i - 1][j] + m[i][j];
		}
	}
	if (cer == 1) {
		long long sm = -21e17, rs = 1, cs = 1, rj = 1, cj = 1;
		for (int i = 1, j = k1; j <= n; i++, j++) {
			long long aux[405], s = 0;
			for (int k = 1; k <= m1; k++) {
				aux[k] = sp[j][k] - sp[i - 1][k];
				if(k <= k1)
					s += aux[k];
			}
			for (int k = k1 + 1; k <= m1; k++) {
				if (sm < s) {
					sm = s;
					rs = i;
					cs = k - k1;
					rj = j;
					cj = k - 1;
				}
				s -= aux[k - k1];
				s += aux[k];
			}
			if (sm < s) {
				sm = s;
				rs = i;
				cs = m1 - k1 + 1;
				rj = j;
				cj = m1;
			}
		}
		cout << sm << '\n';
		cout << rs << ' ' << cs << ' ' << rj << ' ' << cj;
	}
	else {
		long long sm = -21e17, rs = 1, cs = 1, rj = 1, cj = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= min(n, i + k1 - 1); j++) {
				long long aux[405], s = 0;
				for (int k = 1; k <= m1; k++)
					aux[k] = sp[j][k] - sp[i - 1][k];
				int l = 0;
				for (int k = 1; k <= m1; k++) {
					s += aux[k];
					l++;
					if (l > k1)
						s -= aux[k - k1], l--;
					if (sm < s) {
						sm = s;
						rs = i;
						cs = k - l + 1;
						rj = j;
						cj = k;
					}
					if (s < 0)
						s = 0, l = 0;
				}
			}
		}
		cout << sm << '\n';
		cout << rs << ' ' << cs << ' ' << rj << ' ' << cj;
	}
}