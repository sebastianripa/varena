#include <iostream>
#include <vector>

using namespace std;

vector <int> v[250005];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int j = 1;
		v[1].clear();
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			if (!v[j].empty() && abs(v[j].back() % 2) == abs(x % 2)) {
				j++;
				v[j].clear();
			}
			v[j].push_back(x);
		}
		int m = j, sm = -21e8;
		for (int i = 1; i <= m; i++) {
			int s = 0;
			for (auto x : v[i]) {
				s += x;
				sm = max(s, sm);
				if (s < 0)
					s = 0;
			}
		}
		cout << sm << '\n';
	}
}