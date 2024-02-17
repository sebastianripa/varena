#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

ifstream cin("interval1.in");
ofstream cout("interval1.out");

vector <int> v;
map <int, int> mp;

signed main() {
	int n, m, x;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		mp[x % m] = 0;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	int dm = 21e8;
	for (auto x : v) {
		if (!mp[x % m]) {
			mp[x % m] = x;
			continue;
		}
		if (x % m == 11991)
			cout << "";
		dm = min(dm, x - mp[x % m]);
		mp[x % m] = x;
		if (dm == 0)
			break;
	}
	cout << dm;
}