#include <fstream>

using namespace std;

ifstream cin("placare.in");
ofstream cout("placare.out");

int m[305][305], vl[305];

int main() {
	int n, m1;
	cin >> n >> m1;
	for (int i = 1; i <= n; i++) {
		int x, j = 1;
		while (true) {
			cin >> x;
			if (x < 0) {
				while (m[i][j])
					j++;
				for (int j1 = i; j1 <= i - x - 1; j1++)
					m[j1][j] = -x;
				j++;
			}
			else {
				int x1 = x;
				while (x) {
					if (!m[i][j]) {
						m[i][j] = x1;
						x--;
					}
					j++;
				}
			}
			while (m[i][j])
				j++;
			if (j-1 == m1)
				break;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m1; j++)
			cout << m[i][j] << ' ';
		cout << '\n';
	}
}