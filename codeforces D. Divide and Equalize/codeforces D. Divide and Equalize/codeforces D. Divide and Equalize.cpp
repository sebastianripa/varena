#include <iostream>
#include <map>

using namespace std;

map <int, int> mp;

bool prim(int n) {
	if (n < 2)
		return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

void desc(int n) {
	int f = 2;
	while (n % f == 0) {
		mp[f]++;
		n /= f;
	}
	f++;
	while (n != 1) {
		while (n % f == 0) {
			mp[f]++;
			n /= f;
		}
		if (prim(n)) {
			mp[n]++;
			return;
		}
		f += 2;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			desc(x);
		}
		bool ok = true;
		for (auto x : mp) {
			if (x.second % n != 0)
				ok = false;
		}
		mp.clear();
		if (ok)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}