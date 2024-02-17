#include <iostream>

using namespace std;

bool verifString(string a, string b, int n, int m) {
	for (int i = 0; i < m; i++) {
		string temp = b.substr(i, n);
		if (temp == a)
			return true;
	}
	return false;
}

string s, x;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		cin >> x;
		cin >> s;
		int ans = 0;
		bool ok = true, ok1 = false;
		if (!verifString(s, x, m, n)) {
			x += x;
			n *= 2;
			ans++;
		}
		else
			ok1 = true;
		if (!verifString(s, x, m, n)) {
			x += x;
			n *= 2;
			ans++;
		}
		else
			ok1 = true;
		while (ok || n < m && !ok1) {
			if (n > m)
				ok = false;
			if (!verifString(s, x, m, n)) {
				x += x;
				n *= 2;
				ans++;
			}
			else {
				ok1 = true;
				break;
			}
		}
		if (!ok1)
			cout << "-1\n";
		else
			cout << ans << '\n';
	}
}