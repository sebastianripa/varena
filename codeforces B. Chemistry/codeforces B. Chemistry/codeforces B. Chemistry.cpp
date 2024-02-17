#include <iostream>
#include <map>

using namespace std;

map <char, int> vf;

int main() {
	int t;
	cin >> t;
	while (t--) {
		vf.clear();
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			char c;
			cin >> c;
			vf[c]++;
		}
		if (n % 2 == 1) {
			bool ok = false;
			for (auto x : vf) {
				if (x.second % 2 && n > 1) {
					if (!ok)
						ok = true;
					else {
						k--;
						n--;
						if (k < 0)
							break;
					}
				}
			}
			if (k <= n && k >= 0)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else {
			for (auto x : vf) {
				if (x.second % 2 && n > 1) {
					k--;
					n--;
					if (k < 0)
						break;
				}
			}
			if (k <= n && k >= 0)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}