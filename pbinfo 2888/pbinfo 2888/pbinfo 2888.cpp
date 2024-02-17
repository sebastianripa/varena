#include <iostream>
#include <vector>

using namespace std;

vector <int> adj[30005];
bool vf[30005];
int v[30005], nd = 1;

void dfs(int n, int st) {
	vf[st] = 1;
	for (auto x : adj[st]) {
		if (!vf[x]) {
			nd++;
			v[x] = nd;
			dfs(n, x);
			nd--;
		}
		else if(nd - v[x] > 1) {
			cout << nd - v[x] + 1;
			exit(0);
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		adj[n1].push_back(n2);
		adj[n2].push_back(n1);
	}
	v[1] = 1;
	dfs(n, 1);
	return 0;
}