#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		bool vf[] = { 0, 0, 0 };
		char a, b, c;
		for (int i = 1; i <= 3; i++) {
			cin >> a >> b >> c;
			if (a == '?') {
				b -= 'A';
				c -= 'A';
				vf[b] = 1;
				vf[c] = 1;
				for (int i = 0; i <= 2; i++) {
					if (!vf[i]) {
						char x = i + 'A';
						cout << x << '\n';
					}
				}
			}
			else if (b == '?') {
				a -= 'A';
				c -= 'A';
				vf[a] = 1;
				vf[c] = 1;
				for (int i = 0; i <= 2; i++) {
					if (!vf[i]) {
						char x = i + 'A';
						cout << x << '\n';
					}
				}
			}
			else if (c == '?') {
				a -= 'A';
				b -= 'A';
				vf[a] = 1;
				vf[b] = 1;
				for (int i = 0; i <= 2; i++) {
					if (!vf[i]) {
						char x = i + 'A';
						cout << x << '\n';
					}
				}
			}
		}
	}
}