#include <fstream>
#include <map>

using namespace std;
ifstream cin("livada.in");
ofstream cout("livada.out");

map <int, int> mp;

int main() {
	int n, m, p, nro = 0, maxi = 0;
	cin >> n >> m >> p;
	for (int i = 1; i <= n; i++) {
		int ogx, mx = 0, nre = 1;
		cin >> ogx;
		mp[ogx]++;
		for (int j = 2; j <= m; j++) {
			int x;
			cin >> x;
			mp[x]++;
			mx = max(mx, mp[x]);
			if (ogx == x)
				nre++;
			else {
				maxi = max(maxi, nre);
				nre = 1;
			}
			ogx = x;
		}
		maxi = max(maxi, nre);
		nre = 1;
		if (mx >= m / 2 + 1)
			nro++;
		mp.clear();
	}
	cout << nro << '\n' << maxi;
}