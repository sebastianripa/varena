#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int x, y, z;
		cin >> x >> y >> z;
		if (x == y)
			cout << z << '\n';
		else if (x == z)
			cout << y << '\n';
		else
			cout << x << '\n';
	}
}