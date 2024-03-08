#include <iostream>
#define MOD 123457

using namespace std;

int rp(int n, int p) {
	int x;
	if (p == 0)
		return 1;
	if (p % 2) {
		x = rp(n, (p - 1) / 2);
		return n * x * x % MOD;
	}
	x = rp(n, p / 2);
	return x * x % MOD;
}

int main() {
	int n;
	cin >> n;
	cout << rp(3, n - 2) * 6 % MOD;
}