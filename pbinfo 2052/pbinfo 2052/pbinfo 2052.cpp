#include <iostream>

using namespace std;

//ifstream cin("curiosity.in");
//ofstream cout("curiosity.out");

pair <int, int> v[100005];
int ans[3];

int main() {
	int st, fn, c, n;
	cin >> st >> fn >> c >> n;
	for (int i = 1; i <= n; i++)
		cin >> v[i].first >> v[i].second;
	int cmx = c;
	v[n + 1].second = fn;
	for (int i = 1; i <= n + 1; i++) {
		if (v[i].second < st)
			continue;
		if (v[i].second > fn)
			break;
		if (v[i - 1].second < st || i == 1) {
			if (v[i].second - st > c) {
				ans[v[i - 1].first] += v[i].second - st - c;
				c = v[i].second - st - c;
			}
			c -= (v[i].second - st);
			if (c < 0) {
				cout << -1;
				exit(0);
			}
			continue;
		}
		if (v[i].second - v[i - 1].second > c) {
			ans[v[i - 1].first] += v[i].second - v[i - 1].second - c;
			c += v[i].second - v[i - 1].second - c;
		}
		else if (v[i - 1].first == 3)
			c = cmx;
		c -= (v[i].second - v[i - 1].second);
	}
	cout << ans[1] << ' ' << ans[2];
}