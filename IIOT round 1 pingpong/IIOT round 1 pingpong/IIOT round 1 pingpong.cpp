#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		if (b > 52 || b >= a || a > 53 || a < 33) {
			cout << "-1 -1\n";
			continue;
		}
		if (a != 33) {
			int pp = a - 33;
			if (pp < 11) {
				b -= 11;
				if (b > 30 || b < 0) {
					cout << "-1 -1\n";
					continue;
				}
				int x = b / 3;
				for (int i = 1; i <= 3; i++) {
					int y = x;
					if (b % 3)
						y++;
					cout << "11 " << y << '\n';
					if (b % 3)
						b--;
				}
				cout << pp << " 11" << '\n';
			}
			else {
				b -= 22;
				if (b > 30 || b < 0) {
					cout << "-1 -1\n";
					continue;
				}
				int x = b / 3;
				for (int i = 1; i <= 3; i++) {
					int y = x;
					if (b % 3)
						y++;
					cout << "11 " << y << '\n';
					if (b % 3)
						b--;
				}
				for (int i = 1; i <= 2; i++)
					cout << pp / 2 << " 11" << '\n';
			}
		}
		else {
			int x = b / 3;
			for (int i = 1; i <= 3; i++) {
				int y = x;
				if (b % 3)
					y++;
				cout << "11 " << y << '\n';
				if (b % 3)
					b--;
			}
		}
	}
}