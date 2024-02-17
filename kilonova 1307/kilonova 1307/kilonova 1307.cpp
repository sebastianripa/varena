#include <fstream>
#include <vector>
#define N 105
#define MOD 13007
#define int unsigned long long

using namespace std;

ifstream cin("perspic.in");
ofstream cout("perspic.out");

int m[N][N];
pair <int, int> mo[N][N];
bool mv[N][N], ms[N][N];

int cmmmc(int a, int b) {
	int p = a * b;
	int r = a % b;
	while (r) {
		a = b;
		b = r;
		r = a % b;
	}
	return p / b;
}

signed main() {
	int n, nro, ans = -1;
	cin >> n >> nro;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			m[i][j] = (i - 1) * n + j;
	}
	for (int i = 1; i <= nro; i++) {
		char c;
		cin >> c;
		int a, b;
		cin >> a >> b;
		if (c == 'E') {
			int x, y;
			cin >> x >> y;
			swap(m[a][b], m[x][y]);
		}
		else {
			if (c == 'R') {
				for (int i = 1; i <= n; i++)
					swap(m[a][i], m[b][i]);
			}
			else {
				for (int i = 1; i <= n; i++)
					swap(m[i][a], m[i][b]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!(m[i][j] % n))
				mo[m[i][j] / n][n].first = i, mo[m[i][j] / n][n].second = j;
			else {
				mo[m[i][j] / n + 1][m[i][j] % n].first = i;
				mo[m[i][j] / n + 1][m[i][j] % n].second = j;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!ms[i][j]) {
				int nrr = 0, aux = m[i][j], is = i, js = j, i = is, j = js;
				do {
					ms[i][j] = true;
					nrr++;
					int aux1 = m[mo[i][j].first][mo[i][j].second];
					m[mo[i][j].first][mo[i][j].second] = m[i][j];
					aux1 = aux;
					int i1 = i;
					i = mo[i1][j].first;
					j = mo[i1][j].second;
				} while (!ms[i][j]);
				if (ans == -1)
					ans = nrr;
				else ans = cmmmc(ans, nrr);
			}
		}
	}
	cout << ans%MOD;
}