#include <fstream>
#define int long long

using namespace std;

ifstream cin("colier.in");
ofstream cout("colier.out");

pair <int, int> v[50005];

int32_t main() {
	int cer, n;
	cin >> cer >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		int mn = 21e9, mx = 0, pmn = 1, pmx = 1, j = 0;
		while (x) {
			j++;
			if (x % 10 < mn)
				mn = x % 10, pmn = j;
			if (mx < x % 10)
				mx = x % 10, pmx = j;
			x /= 10;
		}
		if (pmn < pmx)
			v[i].first = mx * 10 + mn, v[i].second = 2;
		else
			v[i].first = mn * 10 + mx, v[i].second = 1;
	}
	if (cer == 1) {
		int nr1 = 0;
		for (int i = 1; i <= n; i++) {
			if (v[i].first % 10 > v[i].first / 10)
				nr1++;
		}
		cout << nr1;
	}
	else {
		int cnt[] = { 0, 0, 0 };
		cnt[v[1].second]++;
		int ans = 0;
		for (int i = 2; i <= n; i++) {
			if (v[i].second == v[i - 1].second)
				cnt[v[i].second]++;
			else {
				ans += cnt[v[i - 1].second] - 1;
				cnt[v[i - 1].second] = 0;
				cnt[v[i].second]++;
			}
		}
		ans += cnt[v[n].second] - 1;
		if (v[1].second == v[n].second && ans != n - 1)
			ans++;
		cout << n - ans;
	}
}