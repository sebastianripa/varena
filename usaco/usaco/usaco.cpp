#include <fstream>
#include <algorithm>
#include <cmath>
#define int long long

using namespace std;

ifstream cin("mountains.in");
ofstream cout("mountains.out");

pair <int, pair<int, int>> v[100005];

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	if (a.first != b.first)
		return a.first < b.first;
	if (a.second.first != b.second.first)
		return a.second.first > b.second.first;
	return a.second.second < b.second.second;
}

int32_t main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> v[i].second.first >> v[i].second.second;
		v[i].first = v[i].second.first - v[i].second.second;
	}
	sort(v + 1, v + n + 1, cmp);
	int ans = 1, p = 1;
	for (int i = 2; i <= n; i++) {
		if (v[p].second.second - (v[i].second.first - v[p].second.first) < v[i].second.second) {
			ans++;
			p = i;
		}
	}
	cout << ans;
}