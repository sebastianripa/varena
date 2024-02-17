#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <pair<int, int>> adj[100005];
priority_queue <pair<int, int>> pq;
vector <bool> cst(100005, false);
int v[100005];

void primMST(int n) {
	vector <bool> visited(n + 1, false);
	pq.push({ 0, 1 });
	while (!pq.empty()) {
		pair <int, int> p = pq.top();
		pq.pop();
		int cn = p.second;
		if (visited[cn])
			continue;
		visited[cn] = true;
		int temp = -p.first;
		cst[temp] = true;
		for (auto x : adj[cn]) {
			if (!visited[x.first])
				pq.push({ -x.second, x.first });
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int n1, n2, w;
		cin >> n1 >> n2 >> w;
		adj[n1].push_back({ n2, w });
		adj[n2].push_back({ n1, w });
		v[i] = w;
	}
	primMST(n);
	for (int i = 1; i <= m; i++)
		cout << v[i] << ' ' << cst[v[i]] << '\n';
}