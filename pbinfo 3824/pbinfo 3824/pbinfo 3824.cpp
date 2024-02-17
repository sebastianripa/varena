#include <fstream>
#include <map>
#define int long long

using namespace std;

map <int, int> mp1, mp2;

ifstream cin("perechi6.in");
ofstream cout("perechi6.out");

signed main() {
	int n, m;
	cin >> n;
	int mini = 21e8, maxi = -21e8;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		mp1[x]++;
		mini = min(mini, x);
		maxi = max(maxi, x);
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int x;
		cin >> x;
		mp2[x]++;
	}
	int ans = 0;
	for (auto x : mp1) {
		if (mp2[x.first])
			ans += x.second * mp2[x.first];
	}
	cout << ans;
}