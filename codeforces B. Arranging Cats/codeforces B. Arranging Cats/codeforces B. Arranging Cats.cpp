#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s1, s2;
		cin >> s1 >> s2;
		int ans = 0, nru1 = 0, nru2 = 0;
		for (int i = 0; i < n; i++) {
			if (s2[i] == '1' && s1[i] == '0')
				ans++;
			if (s1[i] == '1')
				nru1++;
			if (s2[i] == '1')
				nru2++;
		}
		cout << ans + max(0, nru1 - nru2) << '\n';
	}
}