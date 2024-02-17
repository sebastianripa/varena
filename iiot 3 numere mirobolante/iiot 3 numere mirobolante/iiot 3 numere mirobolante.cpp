#include <iostream>
#define MOD 1000000007

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int s = 3 - n % 3 + n;
		if (s % 3 == 0)
			s -= 3;
		while (s % 4 != n % 4)
			s += 3;
		int k = (s - n) / 4, ans = 1;
		for (int i = k + 1; i <= n; i++) {
			ans = ans * (i % MOD);
			ans %= MOD;
		}
		cout << ans;
	}
}