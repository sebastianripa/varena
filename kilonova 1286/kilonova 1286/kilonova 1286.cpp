#include <fstream>

using namespace std;

ifstream cin("div.in");
ofstream cout("div.out");

int ansl[5005], ansr[5005];

void precalc(string s, int m) {
	ansl[0] = (s[0] - '0') % m;
	for (int i = 1; i < s.size(); i++)
		ansl[i] = (ansl[i - 1] * 10 + (s[i] - '0')) % m;
	for (int i = 0; i < s.size(); i++) {
		for (int j = i; j < s.size(); j++)
			ansr[i] = (ansr[i] * 10 + s[j] - '0') % m;
	}
}

signed main() {
	int m;
	cin >> m;
	string n;
	cin >> n;
	precalc(n, m);
	if (!ansl[n.size() - 1])
		cout << "0 0", exit(0);
	for (int i = 1; i <= n.size(); i++) {
		for (int j = 0; j + i - 1 < n.size(); j++) {
			int ans = 0;
			if(j > 0)
				ans = ansl[j - 1];
			bool z = 1;
			int nrz = 0;
			for (int k = j + i; k < n.size(); k++) {
				if (z && !(n[k] - '0'))
					nrz++;
				else
					z = 0;
				ans = ans * 10 + (n[k] - '0');
				ans %= m;
			}
			if (j != 0)
				nrz = 0;
			if (ans == 0)
				cout << j + 1 << ' ' << j + nrz + i, exit(0);
		}
	}
	cout << "1 " << n.size();
}