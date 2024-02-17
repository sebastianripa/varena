#include <iostream>

using namespace std;

int m[405][405], sp[405][405];

void formMatrix(int a, int b, int c, int d, int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			m[i][j] = (a * i + b * j + c) % d;
	}
}

int main() {
	int t, n, a, b, c, d;
	cin >> t >> n >> a >> b >> c >> d;
	formMatrix(a, b, c, d, n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			sp[i][j] = sp[i - 1][j] + m[i][j];
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			int aux[405];
			for (int k = 1; k <= n; k++)
				aux[k] = sp[j][k] - sp[i - 1][k];
			int l = 1, r = 1, s = 0;
			while (l <= r && r <= n) {
				s += aux[r];
				while (s > t && l <= r) {
					s -= aux[l];
					l++;
				}
				if(s <= t)
					ans += (r - l + 1);
				r++;
			}
		}
	}
	cout << ans;
}