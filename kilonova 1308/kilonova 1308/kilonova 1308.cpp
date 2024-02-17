#include <fstream>

using namespace std;

ifstream cin("rafturi.in");
ofstream cout("rafturi.out");

int v[10005];

int main() {
	int c, n;
	cin >> c >> n;
	int mini = 21e8;
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		v[x] = max(v[x], y);
		mini = min(mini, x);
	}
	int ans = 0;
	for (int i = 2; i <= c; i += 3)
		ans += max(v[i], max(v[i - 1], v[i + 1]));
	cout << ans;
}