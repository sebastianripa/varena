#include <fstream>
#include <vector>
#define int long long

using namespace std;

ifstream cin("deminare.in");
ofstream cout("deminare.out");

vector <int> c1;
int vf[505], m[505][505], sp[505][505];
vector <pair<int, int>> vd;

int32_t main() {
	int cer, n, m1;
	cin >> cer >> n >> m1;
	if (cer == 1) {
		int mx = 0;
		int q;
		cin >> q;
		for (int i = 1; i <= q; i++) {
			int x, y;
			cin >> x >> y;
			vf[x]++;
			if (mx < vf[x]) {
				c1.clear();
				mx = vf[x];
				c1.push_back(x);
			}
			else if (mx == vf[x])
				c1.push_back(x);
		}
		for (auto x : c1)
			cout << x << ' ';
	}
	else {
		int q;
		cin >> q;
		for (int i = 1; i <= q; i++) {
			int x, y;
			cin >> x >> y;
			m[x][y] = 1;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m1; j++)
				sp[i][j] = sp[i - 1][j] + m[i][j];
		}
		for (int i = 1; i * i <= q; i++) {
			if (!(q % i))
				vd.push_back({ i, q / i });
		}
		int sm = -1;
		for (pair<int, int> x : vd) {
			int l1 = x.first, l2 = x.second;
			if (l1 <= m1 && l2 <= n) {
				for (int i = 1, j = l2; j <= n; i++, j++) {
					int aux[505], s = 0;
					for (int k = 1; k <= m1; k++) {
						aux[k] = sp[j][k] - sp[i - 1][k];
						if (k <= l1)
							s += aux[k];
					}
					for (int k = l1 + 1; k <= m1; k++) {
						sm = max(sm, s);
						s -= aux[k - l1];
						s += aux[k];
					}
					sm = max(sm, s);
				}
			}
			if (l1 <= n && l2 <= m1) {
				for (int i = 1, j = l1; j <= n; i++, j++) {
					int aux[505], s = 0;
					for (int k = 1; k <= m1; k++) {
						aux[k] = sp[j][k] - sp[i - 1][k];
						if (k <= l2)
							s += aux[k];
					}
					for (int k = l2 + 1; k <= m1; k++) {
						sm = max(sm, s);
						s -= aux[k - l2];
						s += aux[k];
					}
					sm = max(sm, s);
				}
			}
		}
		if (sm != -1)
			cout << q - sm;
		else
			cout << sm;
	}
}