#include <iostream>

using namespace std;

int m[170][170];

int main() {
	int n, nri;
	cin >> n >> nri;
	int l = n, h = n;
	for (int i = 1; i <= nri; i++) {
		int ti, x;
		cin >> ti >> x;
		if (ti == 1) {
			if (x > l / 2)
				x = l - x;
			m[1][1]++;
			m[1][x + 1]--;
			l -= x;
		}
		else {
			if (x > h / 2)
				x = h - x;
			m[1][1]++;
			m[x + 1][1]--;
			h -= x;
		}
	}
	int g = 0;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= l; j++)
			m[i][j] = m[i - 1][j] + m[i][j - 1] - m[i - 1][j - 1], g = max(g, m[i][j]);
	}
	cout << h << ' ' << l << ' ' << g + 1;
}
