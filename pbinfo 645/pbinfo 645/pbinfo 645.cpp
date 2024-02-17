#include <fstream>
#include <vector>
#define int long long

using namespace std;

ifstream cin("detdrum3.in");
ofstream cout("detdrum3.out");

vector <int> adj[105];
vector <int> vs, vsm;
int v[105], sm = -1;

void dfs(int n, int p, int sum) {
	sum += v[n];
	vs.push_back(n);
	for (auto x : adj[n]) {
		if (x != p)
			dfs(x, n, sum);
	}
	if (adj[n].empty()) {
		if (sum > sm) {
			vsm = vs;
			sm = sum;
		}
		else if (sum == sm && n < vsm.back())
			vsm = vs;
	}
	sum -= v[n];
	vs.pop_back();
}

int32_t main() {
	int n, k = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (x)
			adj[x].push_back(i);
		else k = i;
	}
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	dfs(k, k, 0);
	cout << sm << '\n';
	for (auto x : vsm)
		cout << x << ' ';
}