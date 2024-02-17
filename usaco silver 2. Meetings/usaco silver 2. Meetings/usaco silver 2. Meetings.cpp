#include <iostream>
#include <algorithm>

using namespace std;

struct cow {
	int p, w, d, t;
};

cow v[50005], v1[50005];

bool cmp(cow a, cow b) {
	if (a.t != b.t)
		return a.t < b.t;
	if (a.p != b.p)
		return a.p < b.p;
}

int main() {
	int n, l, wt = 0;
	cin >> n >> l;
	for (int i = 1; i <= n; i++) {
		cin >> v[i].w >> v[i].p >> v[i].d;
		wt += v[i].w;
		if (v[i].d == 1)
			v[i].t = l - v[i].p;
		else
			v[i].t = v[i].p;
		v1[i] = v[i];
	}
	sort(v1 + 1, v1 + n + 1, cmp);
	int ws = 0, i = 1;
	while (ws < wt) {
		ws += v1[i].w;
		if (v1[i + 1].w == v1[i].w) {
			ws += v1[i + 1].w;
			i++;
		}
		i++;
	}
	i--;
	for (int i = 1; i <= n; i++) {

	}
}