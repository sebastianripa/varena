#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		if ((max(a, b) - min(a, b)) % 2)
			cout << "Alice" << '\n';
		else cout << "Bob" << '\n';
	}
}