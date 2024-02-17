#include <iostream>
#include <set>
#include <map>

using namespace std;

set <int> s;
map <int, bool> mp;
set <int> v;

int main() {
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		s.insert(x);
		mp[x] = 1;
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int x;
		cin >> x;
		s.insert(x);
		if (mp[x])
			v.insert(x);
	}
	for (auto x : s)
		cout << x << ' ';
	cout << '\n';
	for (auto x : v)
		cout << x << ' ';
}