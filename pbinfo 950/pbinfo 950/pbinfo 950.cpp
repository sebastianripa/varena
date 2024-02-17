#include <fstream>
#include <algorithm>

using namespace std;

ifstream cin("cerc3.in");
ofstream cout("cerc3.out");

pair <int, int> v[305];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		v[i].first = x - y;
		v[i].second = x + y;
	}
	sort(v + 1, v + n + 1);
	int ans = 0, st = 1e9;
	for (int i = n; i >= 1; i--) {
		if (v[i].second < st) {
			ans++;
			st = v[i].first;
		}
	}
	cout << ans;
}