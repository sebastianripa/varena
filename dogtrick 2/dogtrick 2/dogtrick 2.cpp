#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int v[250005], groups[250005];
vector <int> edge[250005];
bool vf[250005];

void dfs(int n, int g) {
	vf[n] = 1;
	groups[n] = g;
	for (auto x : edge[n]) {
		if (!vf[x])
			dfs(x, g);
	}
}

int main() {
	int n, q, mx = 0;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> v[i], mx = max(mx, v[i]);
	cin >> q;
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		edge[x].push_back(y);
	}
	int g = 1;
	for (int i = 1; i <= mx; i++) {
		if (!edge[i].empty())
			sort(edge[i].begin(), edge[i].end());
		if (!groups[i])
			dfs(i, g), g++;
	}
	int ans = 2;
	for (int i = 2; i <= n; i++) {
		int pz = lower_bound(edge[v[i - 1]].begin(), edge[v[i - 1]].end(), v[i]) - edge[v[i - 1]].begin();
		if (edge[v[i - 1]].empty())
			break;
		if (pz == edge[v[i - 1]].size())
			pz--;
		if (edge[v[i - 1]][pz] == v[i])
			ans += 2;
		else if (groups[v[i - 1]] == groups[v[i]])
			ans++;
		else break;
	}
	cout << ans;
}