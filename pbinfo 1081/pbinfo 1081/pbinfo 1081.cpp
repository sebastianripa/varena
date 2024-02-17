#include <fstream>
#define int long long

using namespace std;

ifstream cin("numar3.in");
ofstream cout("numar3.out");

int dc(int a, int b) {
	int r = a % b;
	while (r) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

int nrc(int n) {
	int nrc = 0;
	while (n /= 10)
		nrc++;
	return nrc + 1;
}

int32_t main() {
	int n, m, a = 0, b = 0, p = 1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		a = a * 10 + x;
	}
	for (int i = 1; i <= m; i++) {
		int x;
		cin >> x;
		a = a * 10 + x;
		p *= 10;
	}
	while (m-- && !(a % 10))
		a /= 10, p /= 10;
	int cmmdc = dc(a, p);
	a /= cmmdc;
	p /= cmmdc;
	int nrc1 = nrc(a), nrc2 = nrc(p);
	cout << nrc1 << '\n' << a << '\n' << nrc2 << '\n' << p;
}