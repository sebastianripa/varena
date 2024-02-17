#include <iostream>

using namespace std;

int nrdiv(int n) {
	int f = 2;
	int nrdiv = 1;
	while (n > 1) {
		int e = 0;
		while (n % f == 0) {
			n /= f;
			e++;
		}
		nrdiv *= (e + 1);
		f++;
	}
	return nrdiv;
}

int main() {
	int n;
	cin >> n;
	cout << nrdiv(n);
}