#include <fstream>
#include <vector>
#include <algorithm>
#define int long long

using namespace std;

ifstream cin("adlic.in");
ofstream cout("adlic.out");

vector <int> v;

signed main() {
	int cer, n;
	cin >> cer >> n;
	if (cer == 1) {
		int maxi = 0;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			if (maxi <= x)
				maxi = x;
			else {
				cout << x;
				break;
			}
		}
	}
	else {
		int nr = 0;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			if (v.empty()) {
				v.push_back(x);
				continue;
			}
			int pz = lower_bound(v.begin(), v.end(), x) - v.begin();
			pz--;
			if(pz >= 0)
				v.erase(v.begin() + pz);
			v.push_back(x);
			sort(v.begin(), v.end());
		}
		cout << v.size();
	}
}