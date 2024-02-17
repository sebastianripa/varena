#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector <pair<int, int>> adj[100005];

int primMST(int n, int stn) {
	vector <bool> visited(n + 2, false);
	priority_queue <pair<int, int>> pq;
	int ans = 0;
	pq.push({ 0, stn });
	while (!pq.empty()) {
		pair <int, int> p = pq.top();
		pq.pop();
		int cn = p.second;
		if (visited[cn])
			continue;
		visited[cn] = true;
		ans -= p.first;
		for (auto x : adj[cn]) {
			if (!visited[x.first])
				pq.push({ -x.second, x.first });
		}
	}
	return ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= m; i++) {
			long long n1, n2, w;
			cin >> n1 >> n2 >> w;
			if (n1 > n2)
				swap(n1, n2);
			w = log2(w);
			adj[n1].push_back({ n2, w });
			adj[n2].push_back({ n1, w });
		}
		cout << primMST(n, 1) + 1 << '\n';
		for (int i = 1; i <= n; i++)
			adj[i].clear();
	}
}