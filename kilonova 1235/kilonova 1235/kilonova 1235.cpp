#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

ifstream cin("sant.in");
ofstream cout("sant.out");

pair <int, int> cp[10005];
pair <int, pair<int, int>> v[10005];
vector <int> p[10005];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> v[i].first >> v[i].second.first, v[i].second.second = i;
	sort(v + 1, v + n + 1);
	int nrp = 1, l = 0, r = 21e8, li = 1;
	for (int i = 1; i <= n; i++) {
		if (r < v[i].first) {
			cp[nrp].first = l;
			cp[nrp].second = r;
			li = i;
			l = v[i].first;
			r = v[i].second.first;
			nrp++;
			p[nrp].push_back(v[i].second.second);
			continue;
		}
		p[nrp].push_back(v[i].second.second);
		r = min(r, v[i].second.first);
		l = v[i].first;
	}
	cp[nrp].first = l;
	cp[nrp].second = r;
	cout << nrp << '\n';
	for (int i = 1; i <= nrp; i++) {
		cout << i << ' ' << cp[i].first << ' ' << cp[i].second << '\n';
		for (auto x : p[i])
			cout << x << ' ';
		cout << '\n';
	}
}