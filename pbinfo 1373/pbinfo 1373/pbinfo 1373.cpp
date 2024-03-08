#include <fstream>

using namespace std;

ifstream cin("reactivi.in");
ofstream cout("reactivi.out");

pair <int, int> v[8005], ans[8005];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> v[i].first >> v[i].second;
	int nrc = 0;
	for (int i = 1; i <= n; i++) {
		int dm = 21e8, pz = 0;
		for (int j = 1; j <= nrc; j++) {
			if ((v[i].first >= ans[j].first && v[i].first <= ans[j].second) || (v[i].second >= ans[j].first && v[i].second <= ans[j].second) || (v[i].first <= ans[j].second && v[i].second >= ans[j].first)) {
				dm = max(0, v[i].first - ans[j].first);
				dm += max(0, ans[j].second - v[i].second);
				pz = j;
			}
		}
		if (dm == 21e8)
			ans[++nrc] = v[i];
		else {
			ans[pz].first = max(ans[pz].first, v[i].first);
			ans[pz].second = min(ans[pz].second, v[i].second);
		}
	}
	cout << nrc;
}