#include <iostream>
#define int long long

using namespace std;

int v[15];

int nrc(int n) {
	int nrc = 0;
	while (n)
		nrc++, n /= 10;
	return nrc;
}

void vct(int n) {
	v[0] = nrc(n);
	int i = 1;
	while (n) {
		v[v[0] - i + 1] = n % 10;
		n /= 10;
		i++;
	}
}

signed main() {
	int n;
	cin >> n;
	int s = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		vct(x);
		bool super = 0;
		for (int i = 1; i <= v[0]/2; i++) {
			bool ok = 1;
			if (v[0] % i)
				continue;
			for (int j = 1; j <= i; j++) {
				int k = j + i;
				while (v[j] == v[k] && k <= v[0]) {
					k += i;
					continue;
				}
				if (k <= v[0]) {
					ok = 0;
					break;
				}
			}
			if (ok) {
				super = 1;
				break;
			}
		}
		if (super)
			s += x;
	}
	cout << s;
}