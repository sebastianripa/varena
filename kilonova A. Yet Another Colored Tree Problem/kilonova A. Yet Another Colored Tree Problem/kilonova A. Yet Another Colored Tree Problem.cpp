#include <iostream>
#include <vector>
#include <map>

using namespace std;

map <int, vector<int>> adj;
map<int, vector<int>> culori;
map <int, int> vb;
int nrb = 0;

void dfs(int st, int r, map <int, int>& vf) {
	vf[st] = 1;
	if (st != r)
		vb[nrb]++;
	for (auto x : adj[st]) {
		if (!vf[x]) {
			if (st == r)
				nrb++;
			dfs(x, r, vf);
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			int c;
			cin >> c;
			culori[c].push_back(i);
		}
		for (int i = 1; i <= n - 1; i++) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		for (int i = 1; i <= k; i++) {
			for (auto x : culori[i]) {
				map <int, int> vf;
				dfs(x, x, vf);
				nrb--;
				for()
			}
		}	
	}
}