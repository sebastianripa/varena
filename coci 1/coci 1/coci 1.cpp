#include <iostream>
#include <algorithm>

using namespace std;

int vv[55];
pair <int, int> vp[55], vvs[55];

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first != b.first)
		return a.first > b.first;
	return vv[a.second] > vv[b.second];
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		vp[x] = { n - i + 1, x };
	}
	for (int i = 1; i <= n; i++) {
		cin >> vvs[i].first;
		vvs[i].second = i;
		vv[i] = vvs[i].first;
	}
	sort(vvs + 1, vvs + n + 1, cmp);
	for (int i = 1; i <= n; i++)
		vp[vvs[i].second].first += n - i + 1;
	sort(vp + 1, vp + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		cout << i << ". Kod";
		if (vp[i].second < 10)
			cout << 0;
		cout << vp[i].second << " (" << vp[i].first << ")\n";
	}
}