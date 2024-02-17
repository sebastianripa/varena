#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		long long nrm = 0, nri = 0;
		for (int i = s.size() - 1; i >= 0; i--) {
			if (s[i] == '0') {
				cout << nrm << ' ';
				if (nrm)
					nrm += nri;
			}
			else {
				nri++;
				nrm++;
			}
		}
		for (int i = 1; i <= nri; i++)
			cout << "-1 ";
		cout << '\n';
	}
	return 0;
}