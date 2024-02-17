#include <iostream>
#include <map>
#include <queue>
#define int long long

using namespace std;

map <double, int> mp;
int v[1000005];

int32_t main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	int l = 1, r = 1, mx = 0, secv = 0;
	while (r <= n) {
		double x = (double)v[r] / 1000;
		if (secv < r - l) {
			double y = (double)v[l] / 1000;
			mp[y]--;
			if (!mp[y])
				secv--;
			l++;
		}
		mp[x]++;
		if (mp[x] == 1)
			secv++;
		if (secv == r - l + 1)
			mx = max(mx, secv);
		r++;
	}
	cout << mx;
}