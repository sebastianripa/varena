#include <iostream>

using namespace std;

int v[200005];

int main() {
	int n;
	cin >> n;
	int ans = 0, l = 0, ogx = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		/*x += v[i];
		for (int j = i; j <= n; j++) {
			if (x < 0)
				v[j] += abs(x) * (j - i + 1);
			else v[j] -= abs(x) * (j - i + 1);
		}*/
		int nr = ogx;
		ogx = x;
		x += l - nr;
		l += -x;
		ans += abs(x);
	}
	cout << ans;
}