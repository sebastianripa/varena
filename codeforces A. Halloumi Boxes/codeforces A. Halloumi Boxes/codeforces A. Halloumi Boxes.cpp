#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k, ogx, x;
		cin >> n >> k >> ogx;
		bool ok = 1;
		for (int i = 2; i <= n; i++) {
			cin >> x;
			if (ogx > x)
				ok = 0;
			ogx = x;
		}
		if (k == 1 && !ok)
			cout << "NO" << '\n';
		else
			cout << "YES" << '\n';
	}
}