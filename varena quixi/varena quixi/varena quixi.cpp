#include <fstream>
#define int long long

using namespace std;

ifstream cin("quixi.in");
ofstream cout("quixi.out");

int v[100005], rasp[100005];

int32_t main() {
	int n;
	cin >> n;
	int ans = 0, nrm = 0;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		int maxi = 0;
		if (nrm <= v[i]) {
			nrm = v[i];
			continue;
		}
		for (int j = i - 1; j >= 1; j--) {
			if (v[j] > v[i]) {
				rasp[i] = maxi + 1;
				break;
			}
			else maxi = max(maxi, rasp[j]);
		}
		ans = max(ans, rasp[i]);
	}
	cout << ans;
}