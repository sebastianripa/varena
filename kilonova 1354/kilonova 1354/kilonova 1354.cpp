#include <fstream>

using namespace std;

ifstream cin("poligon.in");
ofstream cout("poligon.out");

int ciur[1005], v[1005];

void eratostene() {
	ciur[1] = 3;
	ciur[2] = 0;
	for (int i = 4; i <= 1000; i += 2)
		ciur[i] = 1;
	for (int i = 3; i <= 1000; i += 2) {
		if (!ciur[i]) {
			ciur[i] = i % 4 - 1;
			for (int j = i * 2; j <= 1000; j += i) {
				if (ciur[j] != 1)
					ciur[j] = i % 4;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	eratostene();
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		if (ciur[v[i]] < 2)
			ans += 2;
	}
	cout << ans;
}