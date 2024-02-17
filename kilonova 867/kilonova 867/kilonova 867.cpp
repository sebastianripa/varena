#include <fstream>
#define int long long

using namespace std;

ifstream cin("palindrom.in");
ofstream cout("palindrom.out");

pair <int, int> ogl(int n) {
	int inv = 0, nrc = 0;
	while (n) {
		inv = inv * 10 + n % 10;
		n /= 10;
		nrc++;
	}
	return { inv, nrc };
}

bool palindrom(int n) {
	int inv = ogl(n).first;
	return n == inv;
}

bool appalindrom(int n) {
	int inv = ogl(n).first;
	int ok = 0;
	while (n) {
		if (inv % 10 != n % 10) {
			if (ok < 2)
				ok++;
			else break;
		}
		inv /= 10;
		n /= 10;
	}
	if (n)
		return false;
	if (!ok)
		return false;
	return true;
}

int nextpal(int n) {
	int m = 1, prim, ultim;
	for (j = 1; j <= k / 2; j++)  m *= 10;
	y = x / m * m + z % m;
	if (y <= x) {
		if (k % 2 == 0)
			a = b = (x / m + 1);
		else
			a = b = (x / m + 1) / 10;
		z = 0;
		while (b)
		{
			z = z * 10 + b % 10;
			b = b / 10;
		}
		y = (x / m + 1) * m + z;
	}
	cout << y << ' ';
}
}

signed main() {
	int cer, n;
	cin >> cer >> n;
	if (cer < 3) {
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			if(cer == 1 && palindrom(x))
				ans++;
			else if (cer == 2 && appalindrom(x))
				ans++;
		}
		cout << ans;
	}
	else {
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			if (i == 7)
				cout << "";
			cout << nextpal(x) << ' ';
		}
	}
}