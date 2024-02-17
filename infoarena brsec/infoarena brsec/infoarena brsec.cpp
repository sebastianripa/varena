#include <fstream>

using namespace std;

ifstream cin("bsrec.in");
ofstream cout("bsrec.out");

pair <int, int> v[1005];
int ans[1005];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		for (int i = 1; i <= n; i++)
			v[i].first = v[i].second = ans[i] = 0;
		while (q--) {
			int x, m;
			cin >> x >> m;
			int oga, ogb, cb, ca;
			cin >> oga >> ogb;
			cb = ogb;
			ca = oga;
			m--;
			int mid = ogb + 1;
			while (m--) {
				int a, b;
				cin >> a >> b;
				if (ogb != b)
					mid = (ogb + oga) / 2;
				oga = a;
				ogb = b;
			}
			if (mid != cb + 1)
				v[mid].first = max(x, v[mid].first);
			if (oga != ca) {
				if (!v[mid - 1].second)
					v[mid - 1].second = x;
				else
					v[mid - 1].second = min(v[mid - 1].second, x);
			}
		}
		bool ok = 1;
		for (int i = 1; i <= n; i++) {
			if (!v[i].first) {
				ans[i] = ans[i - 1] + 1;
				if (ans[i] >= v[i].second && v[i].second) {
					cout << -1 << '\n';
					ok = 0;
					break;
				}
			}
			else {
				ans[i] = max(v[i].first, ans[i - 1] + 1);
				if (ans[i] < ans[i - 1]) {
					cout << -1 << '\n';
					ok = 0;
					break;
				}
			}
		}
		if (ok) {
			for (int i = 1; i <= n; i++)
				cout << ans[i] << ' ';
			cout << '\n';
		}
	}
}