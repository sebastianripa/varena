#include <fstream>

using namespace std;

ifstream cin("origami.in");
ofstream cout("origami.out");

int m[505][505];

int reset1(int st, int h) {
	int idx = st - 1, maxi = 0;
	for (int i = 1; i <= h; i++) {
		for (int j = st; m[i][j]; j++)
			maxi = max(maxi, m[i][j]), m[i][j - idx] = m[i][j], m[i][j] = 0;
	}
	return maxi;
}

int reset2(int st, int l) {
	int idx = st - 1, maxi = 0;
	for (int j = 1; j <= l; j++) {
		for(int i = st; m[i][j]; i++)
			maxi = max(maxi, m[i][j]), m[i - idx][j] = m[i][j], m[i][j] = 0;
	}
	return maxi;
}

int main() {
	int n;
	cin >> n;
	int l = n, h = n, nri, g = 1;
	cin >> nri;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			m[i][j] = 1;
	}
	while (nri--) {
		int tip, idx;
		cin >> tip >> idx;
		int d = idx * 2 - 1;
		if (tip == 1) {
			for (int j = 1; j <= idx; j++) {
				for (int i = 1; i <= h; i++)
					m[i][j + d] += m[i][j], m[i][j] = 0;
				d -= 2;
			}
			g = max(g, reset1(idx + 1, h));
			if (idx > l / 2)
				idx = l - idx;
			l -= idx;
		}
		else {
			for (int i = 1; i <= idx; i++) {
				for(int j = 1; j <= l; j++)
					m[i + d][j] += m[i][j], m[i][j] = 0;
				d -= 2;
			}
			g = max(g, reset2(idx + 1, l));
			if (idx > h / 2)
				idx = h - idx;
			h -= idx;
		}
	}
	cout << h << ' ' << l << ' ' << g;
}