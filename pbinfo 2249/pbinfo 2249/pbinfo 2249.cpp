#include <fstream>
#include <vector>
#include <climits>

using namespace std;

ifstream cin("panouri.in");
ofstream cout("panouri.out");

bool vf1[1005];
int v[150005], vf[1005];
vector <pair<int, int>> vp;

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	for (int i = 1; i <= k; i++) {
		int x;
		cin >> x;
		vf1[x] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (vf1[v[i]])
			vp.push_back({ v[i], i });
	}
	int l = 0, r = 1, nrec = 0, mn = INT_MAX;
	n = vp.size() - 1;
	vf[vp[0].first]++;
	nrec++;
	while (l <= n) {
		if (nrec == k || r - 1 == n) {
			if(nrec == k)
				mn = min(mn, vp[r - 1].second - vp[l].second);
			if (l == r && nrec == k)
				break;
			vf[vp[l].first]--;
			if (!vf[vp[l].first])
				nrec--;
			l++;
			continue;
		}
		if (!vf[vp[r].first])
			nrec++;
		vf[vp[r].first]++;
		r++;
	}
	cout << mn;
}