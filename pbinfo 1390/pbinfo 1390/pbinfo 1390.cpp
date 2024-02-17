#include <fstream>
#define ll long long

using namespace std;

ifstream cin("cartele.in");
ofstream cout("cartele.out");

bool m[1005][1005];

int main() {
	ll n, c;
	cin >> n >> c;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++)
			cin >> m[i][j];
	}
	while (c--) {
		bool oka = true, okb = true, okc = true, okd = true, oka1 = true, okb1 = true, okc1 = true, okd1 = true;
		for (ll i = 1; i <= n; i++) {
			for (ll j = 1; j <= n; j++) {
				ll a = -1, b = -1, c = -1, d = -1, a1 = -1, b1 = -1, c1 = -1, d1 = -1, x;
				if(oka)
					a = m[i][j];
				if(okb)
					b = m[j][n - i + 1];
				if(okc)
					c = m[n - i + 1][n - j + 1];
				if(okd)
					d = m[n - j + 1][i];
				if (oka1)
					a1 = m[i][n - j + 1];
				if (okb1)
					b1 = m[j][i];
				if (okc1)
					c1 = m[n - i + 1][j];
				if (okd1)
					d1 = m[n - j + 1][n - i + 1];
				cin >> x;
				if (oka && x != a)
					oka = false;
				if (okb && x != b)
					okb = false;
				if (okc && x != c)
					okc = false;
				if (okd && x != d)
					okd = false;
				if (oka1 && x != a1)
					oka1 = false;
				if (okb1 && x != b1)
					okb1 = false;
				if (okc1 && x != c1)
					okc1 = false;
				if (okd1 && x != d1)
					okd1 = false;
			}
		}
		if (oka || okb || okc || okd || oka1 || okb1 || okc1 || okd1)
			cout << "1\n";
		else
			cout << "0\n";
	}
	return 0;
}