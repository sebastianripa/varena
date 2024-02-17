#include <iostream>
#define int long long

using namespace std;

int v[300005];
pair <int, pair<int, int>> nopti[300005];

signed main() {
	int n;
	cin >> n;
	int nri = 0, nrnm = 21e16, j = 1, ans = 0;
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		v[i] = c - '0';
		if (v[i] == 1) {
			nri++;
			continue;
		}
		if (nri == 0)
			continue;
		if (nri % 2) {
			nrnm = min(nrnm, nri / 2);
			nopti[j].first = nri / 2;
			nopti[j++].second.first = nri / 2;
			ans++;
			nri = 0;
			continue;
		}
		int nrn;
		if (nri % 4 == 2)
			nrn = (nri / 2 - 1) / 2;
		else  nrn = nri / 4, nopti[j].second.second = 1;
		nrnm = min(nrnm, nri / 2 - 1);
		nopti[j].first = nrn;
		nopti[j++].second.first = nri / 2 - 1;
		ans += 2;
		nri = 0;
	}
	if (nri) {
		if (nri % 2) {
			nrnm = min(nrnm, nri / 2);
			nopti[j].first = nri / 2;
			nopti[j++].second.first = nri / 2;
			ans++;
			nri = 0;
		}
		else {
			int nrn;
			if (nri % 4 == 2)
				nrn = (nri / 2 - 1) / 2;
			else  nrn = nri / 4;
			nrnm = min(nrnm, nri / 2 - 1);
			nopti[j].first = nrn;
			nopti[j++].second.first = nri / 2 - 1;
			ans += 2;
			nri = 0;
		}
	}
	j--;
	for (int i = 1; i <= j; i++) {
		if (nopti[i].second.first == nopti[i].first) {
			ans += (nopti[i].first - nrnm) * 2;
			continue;
		}
		if (nopti[i].first > nrnm) {
			if(!nopti[i].second.second)
				ans += (nopti[i].first - nrnm) * 4;
			else {
				ans += 2;
				ans += (nopti[i].first - nrnm - 1) * 4;
			}
		}
	}
	cout << ans;
}