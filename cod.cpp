#include <iostream>

using namespace std;

struct turn {
	int emx, emn, omx, omn;
};

int n;
bool afisat;
turn v[300005];
string s[300005];

void bkt(int b, int pz) {
	if (afisat)
		return;
	if (b <= 0)
		return;
	if (pz > n) {
		afisat = 1;
		for (int i = 1; i <= n; i++) {
			cout << s[i];
			if (i != n)
				cout << ' ';
		}
		return;
	}
	if (v[pz].omn == 21e8) {
		s[pz] = "Even";
		bkt(b + v[pz].emn, pz + 1);
	}
	else if (v[pz].emn == 21e8) {
		s[pz] = "Even";
		bkt(b - v[pz].omx, pz + 1);
		s[pz] = "Odd";
		bkt(b + v[pz].omn, pz + 1);
	}
	else {
		s[pz] = "Even";
		bkt(b - v[pz].omx, pz + 1);
		s[pz] = "Odd";
		bkt(b - v[pz].emx, pz + 1);
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int b, k;
		cin >> b >> n >> k;
		afisat = 0;
		for (int i = 1; i <= n; i++) {
			v[i].omn = 21e8;
			v[i].emn = 21e8;
			v[i].omx = 0;
			v[i].emx = 0;
			for (int j = 1; j <= k; j++) {
				int x;
				cin >> x;
				if (x % 2) {
					v[i].omx = max(v[i].omx, x);
					v[i].omn = min(v[i].omn, x);
				}
				else {
					v[i].emx = max(v[i].emx, x);
					v[i].emn = min(v[i].emn, x);
				}
			}
		}
		bkt(b, 1);
		if (!afisat)
			cout << -1;
		cout << '\n';
	}
}