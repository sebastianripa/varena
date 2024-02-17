#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int nrsz = 0;
		bool z = 0;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			if (x < 0)
				nrsz++;
			else if (x == 0)
				z = 1;
		}
		if (z || nrsz % 2)
			cout << "0\n";
		else
			cout << "1\n1 0\n";
	}
}