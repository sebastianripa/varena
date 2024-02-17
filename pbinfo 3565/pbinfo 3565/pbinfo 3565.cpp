#include <fstream>

using namespace std;

ifstream cin("furnici1.in");
ofstream cout("furnici1.out");

int main() {
	int l, n, ans = 0;
	cin >> l >> n;
	for (int i = 1; i <= n; i++) {
		char c;
		int pz;
		cin >> pz >> c;
		if (c == 'S')
			ans = max(ans, pz);
		else
			ans = max(ans, l - pz);
	}
	cout << ans;
}