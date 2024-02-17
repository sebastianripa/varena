#include <iostream>
#include <vector>
#define int long long

using namespace std;

int nivel[1000005], tati[1000005];
vector <int> edge[1000005];

void dfs(int lst, int n) {
	nivel[n] = nivel[lst] + 1;
	for (auto x : edge[n])
		dfs(n, x);
}

signed main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		edge[x].push_back(y);
		tati[y] = x;
	}
	nivel[0] = -1;
	dfs(0, 0);
	for (int i = 0; i < n; i++) {
		cout << nivel[i] << ' ';
	}
}