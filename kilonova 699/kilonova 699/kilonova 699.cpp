#include <fstream>

using namespace std;

ifstream cin("poarta.in");
ofstream cout("poarta.out");

pair <int, int> m[255][255];
pair <int, int> v[255];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		long long a, b, c, d;
		cin >> a >> b >> c >> d;
		m[a][b] = { c, d };
	}
	int ans = 0;
	for (int i = 1; i <= 250; i++) {
		for (int j = 1; j <= 250; j++) {
			int x = i, y = j;
			if (m[x][y].first != 0) {
				if (m[x][y] == make_pair(x, y))
					continue;
				int a = m[x][y].first, b = m[x][y].second;
				m[x][y] = { 0, 0 };
				while (a) {
					if (a == x && b == y) {
						a = 0;
						ans++;
					}
					ans++;
					int ca = a, cb = b;
					a = m[ca][cb].first;
					b = m[ca][cb].second;
					m[ca][cb] = { 0, 0 };
				}
			}
		}
	}
	cout << ans;
}