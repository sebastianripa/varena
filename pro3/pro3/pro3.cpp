#include <fstream>
#define maxVal 1e6
#define int long long

using namespace std;

ifstream cin("pro3.in");
ofstream cout("pro3.out");

struct pa {
	int s, r, n;
};

int cmmmc(int a, int b) {
	int r = a % b;
	int ca = a, cb = b;
	while (r) {
		a = b;
		b = r;
		r = a % b;
	}
	return ca * cb / b;
}

pa nri(pa x, pa y) {
	int lim = min(x.s + (x.n - 1) * x.r, y.s + (y.n - 1) * y.r);

	for (int i = 0; i < maxVal; i++) {
		if (x.s + x.r * i <= lim && (x.s - y.s + x.r * i) % y.r == 0 && x.s + (x.r * i) >= y.s) {
			return { x.s + x.r * i, cmmmc(x.r,y.r), ((lim - (x.s + x.r * i)) / cmmmc(x.r, y.r) + 1) };
		}
	}
	return { 0, 0, 0 };
}

signed main() {
	pa a, b, c;
	cin >> a.s >> a.r >> a.n;
	cin >> b.s >> b.r >> b.n;
	cin >> c.s >> c.r >> c.n;
	cout << (a.n + b.n + c.n) - nri(a, b).n - nri(b, c).n - nri(a, c).n + nri(nri(a, b), c).n;
}