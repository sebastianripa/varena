#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 105;
vector <vector<pair<int, int>>> adj;
priority_queue <pair<int, int>> pq;

int primMST(int n, int st) {
	pq.push({ 0, st });
	vector <bool> visited(N, 0);
	int ans = 0;
	while (!pq.empty()) {
		pair <int, int> p = pq.top();
		pq.pop();
		int cn = p.second;
		if (visited[cn])
			continue;
		visited[cn] = 1;
		ans -= p.first;
		for (auto x : adj[cn]) {
			if (!visited[x.first])
				pq.push({ -x.second, x.first });
		}
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	adj.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			if (!x)
				continue;
			adj[i].push_back({ j, x });
		}
	}
	int mini = 105;
	for (int i = 1; i <= n; i++)
		mini = min(mini, primMST(n, 1));
	cout << mini;
}