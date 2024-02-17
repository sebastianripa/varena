#include <iostream>
#include <vector>
#include <set>

using namespace std;

int sp[2605][2605];
vector <pair<int, int>> v;
set <int> s;
vector <int> temp;
int vn[7005];

int normalizare(int n) {
	return upper_bound(temp.begin(), temp.end(), n) - temp.begin();
}

int gcd(int a, int b) {
	int r = a % b;
	while (r) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 1; i <= 90; i++) {
		for (int j = i; 2 * i * j <= 7000 && j * j - i * i <= 700; j++) {
			if (gcd(j * j - i * i, 2 * i * j) == 1) {
				v.push_back({ j * j - i * i, 2 * i * j });
				v.push_back({ 2 * i * j, j * j - i * i });
				s.insert(j * j - i * i);
				s.insert(2 * i * j);
			}
		}
	}
	for (auto x : s)
		temp.push_back(x);
	for (auto x : v)
		sp[normalizare(x.first)][normalizare(x.second)] = 1;
	n = temp.size();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			sp[i][j] = sp[i - 1][j] + sp[i][j - 1] - sp[i - 1][j - 1];
	}
	for (int i = 0; i <= 7000; i++)
		vn[i] = normalizare(i);
	for (int i = 1; i <= q; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		swap(x2, y2);
		x1 = vn[x1 - 1];
		y1 = vn[x2 - 1];
		x2 = vn[x2];
		y2 = vn[y2];
		cout << sp[x2][y2] - sp[x1][y2] - sp[x2][y1] + sp[x1][y1] << '\n';
	}
}