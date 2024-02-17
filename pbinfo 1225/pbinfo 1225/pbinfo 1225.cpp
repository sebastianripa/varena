#include <fstream>
#include <algorithm>
#include <vector>
#define int long long

using namespace std;

ifstream cin("sort2dist.in");
ofstream cout("sort2dist.out");

string v[1005], vs[1005];
vector <pair<int, int>> ans;

bool cmp(string a, string b) {
	if (a.size() != b.size())
		return a.size() < b.size();
	return a < b;
}

signed main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> v[i], vs[i] = v[i];
	sort(vs + 1, vs + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		int j = i;
		while (v[j] != vs[i])
			j++;
		int d = j - i;
		while (d) {
			int s = (d & -d);
			ans.push_back({ d + i - s, d + i });
			swap(v[d + i - s], v[d + i]);
			d -= (d & -d);
		}
	}
	cout << ans.size() << '\n';
	for (auto x : ans)
		cout << x.first << ' ' << x.second << '\n';
}