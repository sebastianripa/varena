#include <fstream>

using namespace std;

ifstream cin("betasah.in");
ofstream cout("betasah.out");

int v[1005];

int main() {
	int n, d, k;
	cin >> n >> d >> k;
	for (int i = 1; i <= d; i++) {
		int x, y;
		cin >> x >> y;
	}
	for (int i = 1; i <= k; i++) {
		int x, y;
		cin >> x >> y;
		v[x]--;
		v[i] += i;
	}
	int maxi = 0;
	for (int i = 1; i <= n; i++) {
		if (i > k)
			v[i] += i;
		maxi = max(maxi, v[i]);
	}
	cout << maxi << '\n' << 0;
}