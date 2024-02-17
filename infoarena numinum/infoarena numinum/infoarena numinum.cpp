#include <iostream>
#include <map>

using namespace std;

//ifstream cin("numinum.in");
//ofstream cout("numinum.out");

map <pair<int, int>, pair<bool, int>> mp;

int main() {
	int n;
	cin >> n;
	while (n--) {
		mp.clear();
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		int nrs1 = 0, nrs2 = 0;
		while (x != a || y != b) {
			if (x != y || a == b) {
				if (x > y)
					x -= y;
				else
					y -= x;
				nrs1++;
				if (!mp[{x, y}].first)
					mp[{x, y}].first = 1, mp[{x, y}].second = nrs1;
				else {
					cout << mp[{x, y}].second + nrs1 << '\n';
					break;
				}
			}
			if (a != b || x == y) {
				if (a > b)
					a -= b;
				else
					b -= a;
				nrs2++;
				if (!mp[{a, b}].first)
					mp[{a, b}].first = 1, mp[{a, b}].second = nrs2;
				else {
					cout << mp[{a, b}].second + nrs2 << '\n';
					break;
				}
			}
		}
	}
}