#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k, nrb = 0;
		cin >> n >> k;
		string s;
		cin >> s;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'B')
				nrb++;
		}
		int ans = 0;
		if (nrb > k) {
			int nr = 0, i;
			for (i = 0; i < n; i++) {
				if (s[i] == 'B')
					nr++;
				if (nrb - nr == k)
					break;
			}
			cout << 1 << '\n';
			cout << i + 1 << " A\n";
		}
		else if (nrb < k) {
			int nr = 0, i;
			for (i = 0; i < n; i++) {
				if (s[i] == 'A')
					nr++;
				if (nrb + nr == k)
					break;
			}
			cout << 1 << '\n';
			cout << i + 1 << " B\n";
		}
		else
			cout << 0 << '\n';
	}
}