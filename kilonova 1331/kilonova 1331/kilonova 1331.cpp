#include <fstream>
#include <vector>
#define ll unsigned long long

using namespace std;

ifstream cin("cmmmc.in");
ofstream cout("cmmmc.out");

int gcd(int a, int b) {
	int r = a % b;
	while (r) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

void fd(int n, vector <int>& v) {
	ll sm = 21e9, ans = 0, l = 0, r = 0;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			v.push_back(i);
			if (i * i != n)
				v.push_back(n / i);
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		vector <int> v;
		int n, ans = 0, l = 0, r = 0;
		ll sm = 21e9;
		cin >> n;
		if (n == 1) {
			cout << "1 1 1\n";
			continue;
		}
		fd(n, v);
		for (int i = 0; i < v.size(); i++) {
			for (int j = i + 1; j < v.size(); j++) {
				if ((ll)v[i] * v[j] / gcd(v[i], v[j]) == n) {
					ans++;
					if (sm > (ll)v[i] + v[j])
						sm = (ll)v[i] + v[j], l = v[i], r = v[j];
				}
			}
		}
		cout << ans + 1 << ' ' << max(l, r) << ' ' << min(l, r) << '\n';
	}
}