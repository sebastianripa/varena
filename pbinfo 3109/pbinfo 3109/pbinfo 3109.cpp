#include <fstream>
#include <algorithm>

using namespace std;

ifstream cin("tunel.in");
ofstream cout("tunel.out");

pair <int, pair<int, int>> v[50005];

int main() {
	int n, lng;
	cin >> n >> lng;
	for (int i = 1; i <= n; i++) {
		cin >> v[i].first >> v[i].second.first;
		if (lng % v[i].second.first >= v[i].first % v[i].second.first)
			v[i].second.second = lng / v[i].second.first - v[i].first / v[i].second.first + 1;
		else
			v[i].second.second = lng / v[i].second.first - v[i].first / v[i].second.first;
	}
	sort(v + 1, v + n + 1);
	int l = 0, lm = 0, ans = 0;
	pair <int, int> mn = { 21e8, 0 };
	for (int i = n; i >= 1; i--) {
		if (mn.first >= v[i].second.first || v[i + 1].second.second < v[i].second.second) {
			mn.first = v[i].second.first;
			mn.second = v[i].second.second;
			lm = max(lm, l);
			l = 0;
			ans++;
		}
		else {

		}
		l++;
	}
	lm = max(lm, l);
	cout << ans << '\n' << lm;
}