#include <fstream>
#include <map>
#define int long long

using namespace std;

ifstream cin("dif2.in");
ofstream cout("dif2.out");

map <int, int> mp;
int v[300005];

signed main() {
	int cer;
	cin >> cer;
	if (cer == 1) {
		int n;
		cin >> n;
		int mini = 21e8, maxi = 0;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			mini = min(mini, x);
			maxi = max(maxi, x);
		}
		int x = maxi * maxi - mini * mini;
		cout << x;
	}
	else {
		int n, st, dr;
		cin >> n >> st >> dr;
		for (int i = 1; i <= n; i++)
			cin >> v[i];
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int p = v[i] * v[j];
				if (!mp[p]) {
					mp[p]++;
					int ans = 0;
					for (auto x : mp) {
						if (x.first == p)
							break;
						ans += x.second;
					}

				}
			}
		}
	}
}