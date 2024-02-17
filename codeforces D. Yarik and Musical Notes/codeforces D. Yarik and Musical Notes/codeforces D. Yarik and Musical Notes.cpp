#include <iostream>
#include <map>
#define int long long

using namespace std;

//int v[200005];
map <double, int> mp;

int32_t main() {
	int t;
	cin >> t;
	while (t--) {
		mp.clear();
		int n;
		cin >> n;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int x;
			//cin >> v[i];
			cin >> x;
			double y = (double)x / 1000;
			ans += mp[y];
			mp[y]++;
		}
		ans += (mp[0.001] * mp[0.002]);
		cout << ans << '\n';
		/*for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (v[i] * (1 << v[j]) == v[j] * (1 << v[i]))
					cout << v[i] << ' ' << v[j] << '\n';
			}
		}*/
	}
}