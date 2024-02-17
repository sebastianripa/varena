#include <fstream>
#define int long long

using namespace std;

ifstream cin("sir10.in");
ofstream cout("sir10.out");

signed main() {
	int n;
	cin >> n;
	int ans = 0, x = n;
	for (int i = 1; true; i++) {
		if (i == 1) {
			ans += (n - 1) * (n - 2) / 2;
			continue;
		}
		if (n % i == 0) {
			if (n / i < 3)
				break;
			ans += ((n / i - 2) * (n / i - 1) / 2) * i;
			continue;
		}
		if (n / i < 2)
			break;
		ans += ((n / i - 1) * (n / i) / 2) * (n%i);
		ans += ((n / i - 2) * (n / i - 1) / 2) * (i - n % i);
	}
	cout << ans;
}