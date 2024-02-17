#include <iostream>

using namespace std;

int v[200005];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> v[i];
		int mn = 21e8, ans = 0;
		for (int i = n; i >= 1; i--) {
			mn = min(mn, v[i]);
			if (mn < v[i]) {
				ans++;
				v[i] = v[i] - mn;
				i++;
			}
		}
		cout << ans << '\n';
	}
}