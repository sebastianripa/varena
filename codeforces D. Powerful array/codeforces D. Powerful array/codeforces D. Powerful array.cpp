#include <iostream>
#include <algorithm>

using namespace std;

const int NMAX = 200005;

struct query {
	int l, r, i;
};

int v[NMAX], bucket[NMAX], vf[(int)1e6+5], ans[NMAX];
query q[NMAX];

void build(int n) {
	int bs = sqrt(n);
	for (int i = 1; i <= n; i++)
		bucket[i] = (i - 1) / bs + 1;
}

bool cmp(query a, query b) {
	if (bucket[a.l] != bucket[b.l])
		return a.l < b.l;
	return a.r < b.r;
}

int update(int temp, int d, int l) {
	temp++;
	temp += 2*d;
	if(!vf[v[l]])
	return temp;
}

void solve(int q1) {
	int l = 1, r = 0, temp = 0;
	for (int i = 1; i <= q1; i++) {
		while (l < q[i].l) temp = update(temp, -vf[v[l]], l);
		while (r < q[i].r) temp = update(temp, vf[v[++l]], l);
		while (l > q[i].l) temp = update(temp, vf[v[--l]], l);
		while (r > q[i].r) temp = update(temp, -vf[v[l]], l);
		ans[q[i].i] = temp;
	}
}

int main() {
	int n, q1;
	cin >> n >> q1;
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	build(n);
	for (int i = 1; i <= q1; i++)
		cin >> q[i].l >> q[i].r, q[i].i = i;
	sort(q + 1, q + q1 + 1, cmp);
	solve(q1);
	for (int i = 1; i <= q1; i++)
		cout << ans[i] << '\n';
}