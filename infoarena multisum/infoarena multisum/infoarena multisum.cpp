#include <iostream>
#include <vector>

using namespace std;

vector <int> ans3;

int main() {
	int t, cer;
	cin >> t >> cer;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int ans1 = 0, ans2 = 0;
		while (a <= b) {
			int n = a - 1;
			int nr = 1, sd = 1;
			while (n) {
				int i;
				for (i = nr * 2; i < n / 2; i += nr) {
					if ((n - i) % i == 0)
						break;
				}
				if (i < n / 2) {
					nr = i;
					n -= nr;
					sd++;
				}
				else {
					n -= n;
					sd++;
				}
			}
			if (ans1 < sd) {
				ans1 = sd;
				ans2 = 1;
				ans3.clear();
				ans3.push_back(a);
			}
			else if (ans1 == sd) {
				ans2++;
				ans3.push_back(a);
			}
			a++;
		}
		if (cer == 1)
			cout << ans1 << '\n';
		else if (cer == 2)
			cout << ans2 << '\n';
		else {
			for (auto x : ans3)
				cout << x << ' ';
			cout << '\n';
		}
	}
}