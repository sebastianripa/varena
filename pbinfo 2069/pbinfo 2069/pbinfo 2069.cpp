#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream cin("roboti2.in");
ofstream cout("roboti2.out");

long long v[100005], mx, vf[100005];
vector <int> sol, ans;

void bkt(int n) {
	if (sol.size() == n) {
		long long s = 0;
		for (int i = 1; i <= n; i++)
			s += sol[(i - 1) % n] * sol[i % n];
		if (s > mx) {
			mx = s;
			ans = sol;
		}
		return;
	}
	for (int i = 1; i <= n; i++) {
		sol.push_back(v[i]);
		if (!vf[i]) {
			vf[i] = 1;
			bkt(n);
			vf[i] = 0;
		}
		sol.pop_back();
	}
}

int main() {
	int cer, n;
	cin >> cer >> n;
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	if (cer == 1) {
		int secv = 0, mx = 0;
		bool ok = true;
		for (int i = 1; ok; i++) {
			if (v[i % n + 1] < v[i % n]) {
				mx = max(mx, secv);
				secv = 0;
				if (i > n)
					ok = false;
			}
			secv++;
		}
		cout << mx;
	}
	else {
		sort(v + 1, v + n + 1);
		bkt(n);
		for (auto x : ans)
			cout << x << ' ';
	}
}