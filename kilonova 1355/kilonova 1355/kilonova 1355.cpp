#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

ifstream cin("stalpi.in");
ofstream cout("stalpi.out");

struct point {
	int x, c;
};

struct sarma {
	double c;
	int a, b;
};

vector <pair<int, int>> colors[105];
point v[10005];
sarma vc[105];

int main() {
	int n, d;
	cin >> n >> d;
	for (int i = 1; i <= n; i++)
		cin >> v[i].x >> v[i].c;
	for (int i = 1; i <= n; i++) {
		int x, c;
		cin >> x >> c;
		vc[c].c = 21e8;
		colors[c].push_back({ x, i });
	}
	double ans = 0;
	for (int i = 1; i <= n; i++) {
		if (vc[v[i].c].c == 21e8)
			sort(colors[v[i].c].begin(), colors[v[i].c].end());
		if (vc[v[i].c].c != d) {
			int l = 0, r = colors[v[i].c].size() - 1, ansbs = colors[v[i].c].size();
			while (l <= r) {
				int mid = (l + r) / 2;
				if (colors[v[i].c][mid].first > v[i].x) {
					r = mid - 1;
					ansbs = mid;
				}
				else if (colors[v[i].c][mid].first < v[i].x)
					l = mid + 1;
				else {
					ansbs = mid;
					break;
				}
			}
			if (l <= r) {
				if(vc[v[i].c].c != 21e8)
					ans -= vc[v[i].c].c;
				ans += d;
				vc[v[i].c].c = d;
				vc[v[i].c].a = i;
				vc[v[i].c].b = colors[v[i].c][ansbs].second;
				continue;
			}
			if (ansbs == 0) {
				int nr = colors[v[i].c][ansbs].first;
				if (vc[v[i].c].c > (double)sqrt(d * d + (nr - v[i].x) * (nr - v[i].x))) {
					if(vc[v[i].c].c != 21e8)
						ans -= vc[v[i].c].c;
					vc[v[i].c].c = (double)sqrt(d * d + (nr - v[i].x) * (nr - v[i].x));
					ans += vc[v[i].c].c;
					vc[v[i].c].a = i;
					vc[v[i].c].b = colors[v[i].c][ansbs].second;
				}
				continue;
			}
			if (ansbs == colors[v[i].c].size()) {
				int nr = colors[v[i].c][ansbs - 1].first;
				if (vc[v[i].c].c > (double)sqrt(d * d + (v[i].x - nr) * (v[i].x - nr))) {
					if (vc[v[i].c].c != 21e8)
						ans -= vc[v[i].c].c;
					vc[v[i].c].c = (double)sqrt(d * d + (v[i].x - nr) * (v[i].x - nr));
					ans += vc[v[i].c].c;
					vc[v[i].c].a = i;
					vc[v[i].c].b = colors[v[i].c][ansbs - 1].second;
				}
				continue;
			}
			if (v[i].x - colors[v[i].c][ansbs - 1].first <= colors[v[i].c][ansbs].first - v[i].x) {
				int nr = v[i].x - colors[v[i].c][ansbs - 1].first;
				if (vc[v[i].c].c > (double)sqrt(d * d + nr * nr)) {
					if (vc[v[i].c].c != 21e8)
						ans -= vc[v[i].c].c;
					vc[v[i].c].c = (double)sqrt(d * d + nr * nr);
					ans += vc[v[i].c].c;
					vc[v[i].c].a = i;
					vc[v[i].c].b = colors[v[i].c][ansbs - 1].second;
				}
				continue;
			}
			int nr = colors[v[i].c][ansbs].first - v[i].x;
			if (vc[v[i].c].c > (double)sqrt(d * d + nr * nr)) {
				if (vc[v[i].c].c != 21e8)
					ans -= vc[v[i].c].c;
				vc[v[i].c].c = (double)sqrt(d * d + nr * nr);
				ans += vc[v[i].c].c;
				vc[v[i].c].a = i;
				vc[v[i].c].b = colors[v[i].c][ansbs].second;
			}
		}
	}
	cout << setprecision(50) << ans << '\n';
	for (int i = 1; i <= 100; i++) {
		if (vc[i].c)
			cout << vc[i].a << ' ' << vc[i].b << '\n';
	}
}