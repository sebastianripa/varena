#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <climits>

using namespace std;

vector <pair<int, int>> adj[200005];
priority_queue <pair<int, int>> pq;

int primMST(int n, int stn) {
	vector <int> visited(n + 2, false);
	int ans = 0;
	pq.push({ 0, stn });
	while (!pq.empty()) {
		pair <int, int> p = pq.top();
		pq.pop();
		if (visited[p.second])
			continue;
		int cn = p.second;
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
	int n, m;
	cin >> n >> m;
	while (n && m) {
		int s = 0;
		for (int i = 1; i <= m; i++) {
			int n1, n2, w;
			cin >> n1 >> n2 >> w;
			if (n1 < n2)
				swap(n1, n2);
			s += w;
			adj[n1].push_back({ n2, w });
			adj[n2].push_back({ n1, w });
		}
		int ans = primMST(n, 0);
		cout << s - ans << '\n';
		for (int i = 0; i < n; i++)
			adj[i].clear();
		cin >> n >> m;
	}
	return 0;
}