#include <fstream>
#include <list>
#include <algorithm>
#include <map>

using namespace std;

ifstream cin("cool.in");
ofstream cout("cool.out");

list <int> q;
int vf[1005], v[5005];

int verif(list <int> v) {
	if (v.empty())
		return false;
	v.sort();
	int i = 0;
	map<int, int> mp;
	for (auto x : v) {
		if (x - v.front() > i)
			return i;
		if (mp[x] > 1)
			return i;
		mp[x]++;
		i++;
	}
	return v.size();
}

int main() {
	int cer, n, k;
	cin >> cer >> n >> k;
	if (cer == 1) {
		int cnt = 0, maxi = 0;
		bool ok = true;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			if (i <= k) {
				if (vf[x] == 0)
					cnt++;
				else if (vf[x] == 1) {
					cnt--;
					ok = false;
				}
				maxi = max(maxi, x);
				vf[x]++;
				q.push_back(x);
			}
		}
		if (ok && verif(q) == q.size())
			cout << maxi;
		else
			cout << cnt;
	}
	else {
		for (int i = 1; i <= n; i++) {
			cin >> v[i];
			if (i < 3) {
				q.push_back(v[i]);
				vf[v[i]]++;
			}
		}
		int l = 1, r = 3;
		int maxi = 0, nrm = 0;
		while (r - 1 <= n) {
			if (vf[v[r - 1]] == 2) {
				q.pop_front();
				q.pop_back();
				int sz = verif(q);
				if (maxi < sz) {
					maxi = sz;
					nrm = 1;
				}
				else if (maxi == sz)
					nrm++;
				q.push_back(v[r - 1]);
				vf[v[l]]--;
				l++;
				continue;
			}
			int sz = verif(q);
			if (maxi < sz) {
				maxi = sz;
				nrm = 1;
			}
			else if (maxi == sz)
				nrm++;
			q.push_back(v[r]);
			vf[v[r]]++;
			r++;
		}
		while (l <= n) {
			q.pop_front();
			vf[v[l]]--;
			l++;
			if (vf[v[r - 1]] == 2)
				q.pop_back();
			int sz = verif(q);
			if (maxi < sz) {
				maxi = sz;
				nrm = 1;
			}
			else if (maxi == sz)
				nrm++;
			if (vf[v[r - 1]] == 2)
				q.push_back(v[r - 1]);
		}
		cout << maxi << '\n' << nrm;
	}
}