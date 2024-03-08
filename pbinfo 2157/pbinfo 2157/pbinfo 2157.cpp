#include <fstream>
#include <algorithm>

using namespace std;

ifstream cin("bomboane3.in");
ofstream cout("bomboane3.out");

pair <int, int> v[10005];
int ans[10005];

int cmmdc(int a, int b) {
	int r = a % b;
	while (r) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

bool cmp(pair <int, int> a, pair <int, int> b) {
	return a.second < b.second;
}

int main() {
	int cer, n;
	cin >> cer >> n;
	if (cer == 1) {
		int mini = 21e8;
		for (int i = 1; i <= n; i++)
			cin >> v[i].first, mini = min(mini, v[i].first);
		for (int i = mini; i >= 1; i--) {
			bool ok = 1;
			for (int j = 2; j <= n; j++) {
				if (v[j].first % i != v[j - 1].first % i) {
					ok = 0;
					break;
				}
			}
			if (ok) {
				cout << i;
				break;
			}
		}
	}
	else {
		for (int i = 1; i <= n; i++)
			cin >> v[i].first, v[i].second = i;
		sort(v + 1, v + n + 1);
		int j = 1;
		for (int i = 1; j <= n; i++) {
			if (v[j].first <= i * (i + 1) / 2)
				ans[v[j++].second] = i - 1, i--;
		}
		sort(v + 1, v + n + 1, cmp);
		for (int i = 1; i <= n; i++) {
			cout << ans[i] << ' ';
			for (int j = 1; j <= ans[i] - 1; j++)
				cout << j << ' ', v[i].first -= j;
			cout << ans[i] + v[i].first << '\n';
		}
	}
}