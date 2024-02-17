#include <iostream>
#pragma optimize("O1")
#pragma optimize("O2")
#pragma optimize("O3")
#pragma optimize("Ofast")
#pragma optimize("unroll-loops")
#define int long long

using namespace std;

int v[200005];

signed main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	for (int i = 1; i <= m; i++) {
		int x;
		cin >> x;
		int h = 1;
		for (int i = 1; i <= n; i++) {
			int y = min(v[i] - h + 1, x - h + 1);
			if (v[i] > x && h != 1)
				y++;
			if (h <= v[i])
				h = v[i] + 1, v[i] += y;
			if (h > x)
				break;
		}
	}
	for (int i = 1; i <= n; i++)
		cout << v[i] << '\n';
}