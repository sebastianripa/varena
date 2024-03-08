#include <fstream>
#define int long long

using namespace std;

ifstream cin("reflex.in");
ofstream cout("reflex.out");

int gcd(int a, int b) {
	int r = a % b;
	while (r) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

signed main() {
	int n, m;
	cin >> n >> m;
	n--;
	m--;
	int d = gcd(n, m);
	int cl = n / d, cla = m / d;
	int colt;
	if (cl % 2 == 0) colt = 4;
	else if (cla % 2 == 0) colt = 2;
	else colt = 3;
	int nr = cl * m + 1;
	cout << nr << ' ' << colt << '\n' << cla - 1 << ' ' << cl - 1;
}