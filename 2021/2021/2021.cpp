#include <iostream>

using namespace std;

int main() {
	int q;
	cin >> q;
	while (q--) {
		long long n, k;
		cin >> n >> k;
		cout << max((long long)0, n - 2 * k + 1) << '\n';
	}
}