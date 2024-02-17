#include <iostream>

using namespace std;

int ie(int n) {
	int d = 2, r = n;
	while (n != 1) {
		if (n % d == 0) {
			r = r / d * (d - 1);
			while (n % d == 0)
				n /= d;
		}
		d++;
		if (d * d > n)
			d = n;
	}
	return r;
}

int main() {
	int n;
	cin >> n;
	cout << ie(n);
}