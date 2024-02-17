#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct DSU {
	vector <int> p, s;
	void init(int n) {
		p.resize(n + 1);
		s.resize(n + 1, 1);
		for (int i = 1; i <= n; i++)
			p[i] = i;
	}
	int f(int x) {
		if (x == p[x])
			return x;
		return p[x] = f(p[x]);
	}
	void unite(int x, int y) {
		x = f(x);
		y = f(y);
		if (s[x] < s[y])
			swap(x, y);
		p[y] = x;
		s[x] += s[x];
	}
};

int main() {
	DSU dsu;
	int n, op;
	cin >> n >> op;
	dsu.init(n);
	while (op--) {
		int cer;
		cin >> cer;
		if (cer == 1) {
			int x, y;
			cin >> x >> y;
			dsu.unite(x, y);
		}
		else if (cer == 2) {
			int x, y;
			cin >> x >> y;
			if (dsu.f(x) == dsu.f(y))
				cout << "DA" << '\n';
			else cout << "NU" << '\n';
		}
		else {
			map <int, int> mp;
			int maxi = 0;
			for (int i = 1; i <= n; i++) {
				int x = dsu.f(i);
				mp[x]++;
				maxi = max(maxi, mp[x]);
			}
			cout << maxi << '\n';
		}
	}
}