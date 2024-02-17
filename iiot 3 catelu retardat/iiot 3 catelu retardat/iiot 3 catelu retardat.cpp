#include <iostream>
#include <map>

using namespace std;

map <pair<int, int>, bool> mp;
bool vf[200005];
int v[200005];

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	int m;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		mp[{a, b}] = 1;
		vf[a] = 1;
		vf[b] = 1;
	}
	bool ok = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (ok == 0) {
			if (i == 1) {
				if (v[i] <= k)
					ans++, ok = 1;
				continue;
			}
			if (v[i] > k)
				cout << 0, exit(0);
			if ((v[i-1] == k+1 && i > 2 && !mp[{v[i - 2], v[i]}])) {
				cout << 0;
				exit(0);
			}
			ans++;
			ok = 1;
			continue;
		}
		if (mp[{v[i - 1], v[i]}]) {
			if (!mp[{v[i], v[i + 1]}] && v[i + 2] == k + 1) {
				ok = 0;
				continue;
			}
			ans++;
			continue;
		}
		ok = 0;
	}
	cout << ans;
}