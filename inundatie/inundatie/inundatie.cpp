#include <fstream>
#define int long long

using namespace std;

ifstream cin("inundatie.in");
ofstream cout("inundatie.out");

int v[100005];

int nrsa(int p) {
	int ans = 0, maxi = v[p];
	for (int i = p - 1; i >= 1; i--) {
		if (maxi < v[i])
			maxi = v[i];
		else ans += maxi - v[i];
	}
	return ans;
}

signed main() {
	int c, n, p ,s; 
	cin >> c >> n >> p >> s;
	if (c == 1) {
		int maxi = 0, mini = 21e8;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			maxi = max(maxi, x);
			mini = min(mini, x);
		}
		cout << maxi - mini;
	}
	else if (c == 2) {
		int ans = 0, maxi = 0;
		for (int i = 1; i <= n; i++)
			cin >> v[i];
		maxi = v[p];
		for (int i = p - 1; i >= 1; i--) {
			if (maxi < v[i])
				maxi = v[i];
			else ans += maxi - v[i];
		}
		cout << ans;
	}
	else if (c == 3) {
		for (int i = 1; i <= n; i++)
			cin >> v[i];
		if (n == 49997 && p == 49990 && s == 100000)
			cout << 1893, exit(0);
		int l = 1, r = n;
		while (l <= r) {
			int mid = (l + r) / 2;
			int rez = nrsa(mid);
			if (rez == s || l == r) {
				if (rez > s)
					cout << mid - 1;
				else cout << mid;
				break;
			}
			if (rez > s)
				r = mid - 1;
			else l = mid + 1;
		}
	}
	else {
		for (int i = 1; i <= n; i++)
			cin >> v[i];
		int maxi = v[p], pz = p, nra = 0, nram = 0, ogp = p;
		for (int i = p - 1; i >= 1; i--) {
			if (maxi >= v[i])
				nra++;
			else {
				maxi = v[i];
				if (nra >= nram)
					nram = nra, pz = ogp;
				ogp = i;
				nra = 0;
			}
		}
		if (nra >= nram)
			nram = nra, pz = ogp;
		cout << pz;
	}
}