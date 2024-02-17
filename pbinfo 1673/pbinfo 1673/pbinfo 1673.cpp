#include <fstream>
#include <vector>
#define int long long

using namespace std;

ifstream cin("cmmdc1.in");
ofstream cout("cmmdc1.out");

vector <pair <int, int>> ans;
int vf[1000005];
int v[1000005];

signed main() {
	int n, k;
	cin >> n >> k;
	int maxi = 0;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		vf[v[i]]++;
		maxi = max(maxi, v[i]);
	}
	for (int i = maxi; i >= 1; i--) {
		int st = maxi;
		if (st % i)
			st -= (st % i);
		int ne = 0;
		for (int j = st; j >= i; j -= i) {
			if (vf[j]) {
				ans.push_back({ j, min(vf[j], (int)(k - ne)) });
				ne += min(vf[j], (int)(k - ne));
				if (ne == k)
					break;
			}
		}
		if (ne == k) {
			cout << i << '\n';
			break;
		}
		ans.clear();
	}
	for (auto x : ans) {
		for (int i = 1; i <= x.second; i++)
			cout << x.first << ' ';
	}
}