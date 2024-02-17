#include <iostream>

using namespace std;

int sumc(long long n) {
	int s = 0;
	while (n) {
		s += n%10;
		n /= 10;
	}
	return s;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		long long n, k;
		cin >> n >> k;
		while (sumc(n) % k)
			n++;
		cout << n << '\n';
	}
}