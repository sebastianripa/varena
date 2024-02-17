#include <iostream>
#include <algorithm>
#include <map>
#define int long long

using namespace std;

int v[100005], v1[100005], sp[100005];
map <double, int> mp;

int32_t main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> v[i];
			v1[i] = v[i];
			sp[i] = 0;
		}
		sort(v + 1, v + n + 1);
		int s = v[1], ans = 0, inc = 1;
		bool ok = false;
		for (int i = 2; i <= n; i++) {
			if (s < v[i]) {
				sp[i] = 1;
				if(ans)
					sp[inc] += ans;
				ans = 0;
				inc = i;
				s += v[i];
				continue;
			}
			ans++;
			s += v[i];
		}
		if (ans)
			sp[inc] += ans;
		for (int i = 1; i <= n; i++)
			sp[i] = sp[i - 1] + sp[i], mp[(double)v[i] / 1000] = sp[i];
		for (int i = 1; i <= n; i++)
			cout << mp[(double)v1[i] / 1000] << ' ';
		cout << '\n';
	}
}