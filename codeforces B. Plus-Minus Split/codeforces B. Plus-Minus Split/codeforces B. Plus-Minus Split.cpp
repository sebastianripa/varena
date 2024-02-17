#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int nrp = 0, nrm = 0;
		for (int i = 1; i <= n; i++) {
			char c;
			cin >> c;
			if (c == '+')
				nrp++;
			else nrm++;
		}
		cout << max(nrp, nrm) - min(nrp, nrm) << '\n';
	}
}