#include <iostream>
#define int unsigned long long

using namespace std;

int sp[150005];

int32_t main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			sp[i] = sp[i - 1] + x;
		}
		int dm = 0;
		for (int i = 1; i <= n / 2; i++) {
			if (!(n % i)) {
				int smx = 0, smn = 21e17;
				for (int j = i; j <= n; j += i) {
					smx = max(smx, sp[j] - sp[j - i]);
					smn = min(smn, sp[j] - sp[j - i]);
				}
				dm = max(dm, smx - smn);
			}
		}
		cout << dm << '\n';
	}
}