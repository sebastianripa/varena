#include <iostream>
#define int long long 

using namespace std;

struct point {
	int t, p;
};

point v[200005];
int vf[200005];

signed main() {
	int n, pz, tt = 0;
	cin >> n >> pz;
	for (int i = 1; i <= n; i++) {
		cin >> v[i].t >> v[i].p;
		if (v[i].t == 1)
			tt++;
	}
	if (tt == 0)
		cout << 0, exit(0);
	int sens = 1, pwr = 1, ans = 0;
	while (1 <= pz && pz <= n) {
		if (v[pz].t == 0)
			sens = -sens, pwr += v[pz].p;
		else if(!vf[pz] && pwr >= v[pz].p)
				ans++, vf[pz] = 1;
		pz += pwr * sens;
		if (ans == tt)
			break;
	}
	cout << ans;
}