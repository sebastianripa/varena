#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int mina = 21e8, maxa = -21e8;
		for (int i = 1; i <= 4; i++) {
			int a, b;
			cin >> a >> b;
			mina = min(mina, a);
			maxa = max(maxa, a);
		}
		cout << (maxa - mina) * (maxa - mina) << '\n';
	}
}