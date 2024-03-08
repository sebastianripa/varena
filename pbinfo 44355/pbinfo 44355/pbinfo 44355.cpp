#include <iostream>
#include <algorithm>

using namespace std;

struct point {
	int n, idx;
};

int v1[1000005], ans[8005];
point v2[8005];

bool cmp(point a, point b) {
	if (a.n != b.n)
		return a.n < b.n;
	return a.idx < b.idx;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> v1[i];
	int m;
	cin >> m;
	for (int i = 1; i <= m; i++)
		cin >> v2[i].n, v2[i].idx = i;
	sort(v2 + 1, v2 + m + 1, cmp);
	int pred = 0, j = 1;
	for (int i = 1; i <= n; i++) {
		if (v1[i] >= v2[j].n) {
			ans[v2[j].idx] = i + pred;
			j++;
			int og = pred;
			while (v2[j - 1].n == v2[j].n && j <= m)
				ans[v2[j].idx] = i + og, j++, pred++;
			pred++;
		}
		if (j > m)
			break;
	}
	while (j <= m) {
		ans[v2[j].idx] = n + pred;
		j++;
		int og = pred;
		while (v2[j - 1].n == v2[j].n && j <= m)
			ans[v2[j].idx] = n + og, j++, pred++;
		pred++;
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << ' ';
}