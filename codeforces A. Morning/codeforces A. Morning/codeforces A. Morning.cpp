#include <iostream>
#include <cmath>

using namespace std;

int v[] = { 10, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int ans = 0;
		for (int i = 0; i < s.size(); i++) {
			if (i == 0)
				ans += v[s[i] - '0'] - v[1];
			else
				ans += (max(v[s[i] - '0'], v[s[i - 1] - '0']) - min(v[s[i] - '0'], v[s[i - 1] - '0']));
			ans++;
		}
		cout << ans << '\n';
	}
}