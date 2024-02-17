#include <fstream>
#include <set>

using namespace std;

ifstream cin("tinta.in");
ofstream cout("tinta.out");

int m[1005][1005];
set <int> ss;

int main() {
	int n;
	cin >> n;
	int nr = 2, i = 1, j = 1;
	m[1][1] = 1;
	while (nr <= n * n) {
		if (i == 1) {
			if (j < n) {
				j++;
				while (j >= 1)
					m[i++][j--] = nr, nr++;
				j++;
				i--;
				continue;
			}
		}
		if (j == 1) {
			if (i < n) {
				i++;
				while (i >= 1)
					m[i--][j++] = nr, nr++;
				i++;
				j--;
				continue;
			}
		}
		if (i == n) {
			if (j < n) {
				j++;
				while (j <= n)
					m[i--][j++] = nr, nr++;
				i++;
				j--;
				continue;
			}
		}
		if (j == n) {
			if (i < n) {
				i++;
				while (i <= n)
					m[i++][j--] = nr, nr++;
				i--;
				j++;
				continue;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << m[i][j] << ' ';
			if (i > 1 && i < n && j > 1 && j < n) {
				int s = m[i - 1][j] + m[i + 1][j] + m[i][j - 1] + m[i][j + 1] + m[i - 1][j - 1] + m[i - 1][j + 1] + m[i + 1][j - 1] + m[i + 1][j + 1];
				ss.insert(s);
			}
		}
		cout << '\n';
	}
	cout << ss.size() << '\n';
	for (auto x : ss)
		cout << x << ' ';
}