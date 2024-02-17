#include <iostream>
#include <vector>

using namespace std;

//ifstream cin("atlarge.in");
//ofstream cout("atlarge.out");

vector <int> adj[100005];
int v[100005], ans = 0, k;

void dfs1(int n, int p) {
	for (auto x : adj[n]) {
		if (x != p)
			dfs1(x, n), v[n] = min(v[n], v[x]);
	}
	if (v[n] == 21e7)
		v[n] = 1;
	else
		v[n]++;
}

void dfs2(int n, int p, int d) {
	if (v[n] <= d) {
		ans++;
		return;
	}
	for (auto x : adj[n]) {
		if (x != p)
			dfs2(x, n, d + 1);
	}
}

int main() {
	int n;
	cin >> n >> k;
	for (int i = 1; i <= n - 1; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		v[i] = 21e7;
	}
	v[n] = 21e7;
	dfs1(k, k);
	dfs2(k, k, 1);
	cout << ans;
}