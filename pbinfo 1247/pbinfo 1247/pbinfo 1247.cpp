#include <fstream>
#include <vector>

using namespace std;

ifstream cin("torturi.in");
ofstream cout("torturi.out");

vector <int> v1, v2;

int main() {
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int x, mx = 0;
		cin >> x;
		if (v1.empty()) {
			v1.push_back(x);
			continue;
		}
		if (v1.back() >= x) {
			if (!v2.empty()) {
				if (v2.back() < v1.back() && v2.back() >= x)
					v2.push_back(x);
				else
					v1.push_back(x);
				continue;
			}
			v1.push_back(x);
			continue;
		}
		if (v2.empty()) {
			v2.push_back(x);
			continue;
		}
		if (v2.back() >= x) {
			v2.push_back(x);
			continue;
		}
		if (v1[0] < x && v2[0] < x) {
			if (v1.back() > v2.back()) {
				ans += v2.size();
				v2.clear();
				v2.push_back(x);
				continue;
			}
			if (v2.back() > v1.back()) {
				ans += v1.size();
				v1.clear();
				v1.push_back(x);
				continue;
			}
			if (v1.size() >= v2.size()) {
				ans += v2.size();
				v2.clear();
				v2.push_back(x);
				continue;
			}
			ans += v1.size();
			v1.clear();
			v1.push_back(x);
			continue;
		}
		vector <int>::iterator pz1 = lower_bound(v1.begin(), v1.end(), x), pz2 = lower_bound(v2.begin(), v2.end(), x);
		if (v1.back() > v2.back()) {
			ans += v2.size() - (pz2 - v2.begin()) + 1;
			v2.erase(pz2, v2.end());
			v2.push_back(x);
			continue;
		}
		if (v2.back() > v1.back()) {
			ans += v1.size() - (pz1 - v1.begin()) + 1;
			v1.erase(pz1, v1.end());
			v1.push_back(x);
			continue;
		}
		if (v1.size() >= v2.size()) {
			ans += v2.size() - (pz2 - v2.begin()) + 1;
			v2.erase(pz2, v2.end());
			v2.push_back(x);
			continue;
		}
		ans += v1.size() - (pz1 - v1.begin()) + 1;
		v1.erase(pz1, v1.end());
		v1.push_back(x);
		continue;
	}
	cout << n - ans;
}