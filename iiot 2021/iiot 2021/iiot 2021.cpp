#include <iostream>

using namespace std;

int main() {
	int q;
	cin >> q;
	while (q--) {
		char c;
		cin.get();
		int cnt = 0, ok = 0;
		while (cin.get(c) && c != '\n') {
			if (c == '.')
				cnt = 0;
			if (c == ' ')
				cnt++;
			if (c == '#') {
				ok = 1;
				if (cnt == 1)
					cout << "First" << '\n';
				else
					cout << "Second" << '\n';
				break;
			}
		}
		if (!ok)
			cout << "Draw" << '\n';
	}
}