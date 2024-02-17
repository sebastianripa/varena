#include <fstream>
#include <cmath>

using namespace std;

ifstream cin("vase1.in");
ofstream cout("vase1.out");

pair<int, char> v[100005];

int main() {
	int n;
	cin >> n;
	long long s = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		char c;
		cin >> x >> c;
		s += (x / 2);
		v[i] = { x, c };
	}
	cout << s << '\n';
	int cc;
	cin >> cc;
	long long st = 0, dr = 0, lvl = 0;
	bool ok = false;
	for (int i = 1; i <= n; i++) {
		if (i == cc) {
			if (v[i].second == 'S') {
				dr = lvl - v[i].first / 2;
				st = lvl + v[i].first / 2;
				ok = true;
			}
			else {
				dr = lvl + v[i].first / 2;
				st = lvl - v[i].first / 2;
				ok = true;
			}
			continue;
		}
		if (!ok)
			lvl += (v[i].first / 2);
		else {
			if (v[i].second == 'S') {
				if (v[cc].second == 'S') {
					st -= (v[i].first / 2);
					dr -= (v[i].first / 2);
				}
				else {
					st += (v[i].first / 2);
					dr += (v[i].first / 2);
				}
			}
			else {
				if (v[cc].second == 'S') {
					st += (v[i].first / 2);
					dr += (v[i].first / 2);
				}
				else {
					st -= (v[i].first / 2);
					dr -= (v[i].first / 2);
				}
			}
		}
	}
	if (v[cc].second == 'D') {
		if (dr <= 0) {
			cout << -st << " S\n" << -dr << " S";
			exit(0);
		}
		if (st >= 0) {
			cout << dr << " D\n" << st << " D";
			exit(0);
		}
		cout << -st << " S\n" << dr << " D";
		exit(0);
	}
	if (st <= 0) {
		cout << -dr << " D\n" << -st << " D";
		exit(0);
	}
	if (dr >= 0) {
		cout << st << " S\n" << dr << " S";
		exit(0);
	}
	cout << st << " S\n" << -dr << " D";
}