#define _USE_MATH_DEFINES
#include <fstream>
#include <math.h>
#include <algorithm>

using namespace std;

ifstream cin("ace.in");
ofstream cout("ace.out");

struct cell {
	double d, u, ud;
};

bool cmp(cell a, cell b) {
	if (a.u != b.u)
		return a.u < b.u;
	return a.d < b.d;
}

cell v[1005 * 1005];

int main() {
	int cer, n, m, k=1;
	cin >> cer >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int x, l1 = n - i, l2 = m - j;
			cin >> x;
			if (x == 0)
				continue;
			double ip = sqrt(l1 * l1 + l2 * l2);
			v[k].d = ip;
			v[k].ud = atan((double)x / ip);
			if (m != j)
				v[k].u = atan((double)l1 / (double)l2);
			else
				v[k].u = M_PI/2;
			k++;
		}
	}
	sort(v + 1, v + k, cmp);
	double lu = v[1].ud;
	int ans = 1;
	for (int i = 2; i <= k - 1; i++) {
		if (cer == 1 && v[i].u != M_PI / 2 && v[i].u != 0) continue;
		if (v[i - 1].u == v[i].u) {
			if (lu < v[i].ud) {
				ans++;
				lu = v[i].ud;
			}
		}
		else {
			ans++;
			lu = v[i].ud;
		}
	}
	cout << ans;
}