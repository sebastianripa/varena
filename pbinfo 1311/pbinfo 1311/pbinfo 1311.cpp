#include <fstream>
#include <vector>
#define fi first
#define se second

using namespace std;

ifstream cin("arc.in");
ofstream cout("arc.out");

vector <pair<int, int>> v;
vector <int> ans;

int main() {
	int cer;
	cin >> cer;
	if (cer == 1) {
		int n, ogx, ans = 1;
		cin >> n >> ogx;
		for (int i = 2; i <= n; i++) {
			int x;
			cin >> x;
			if (x != ogx)
				ans++;
			if(i < n)
				ogx = x;
		}
		cout << ans;
	}
	else {
		int n;
		cin >> n;
		int ogx;
		cin >> ogx;
		v.push_back({ ogx, 1 });
		for (int i = 2; i <= n; i++) {
			int x;
			cin >> x;
			if (ogx != x)
				v.push_back({ x, i });
			ogx = x;
		}
		for (int i = 1; i < v.size(); i++) {
			if (v[i].se - v[i - 1].se > 2) {
				int sz = v[i].se - v[i - 1].se;
				v.erase(v.begin() + (i - 1));
				i--;
				n -= sz;
				for (int j = i; j < v.size(); j++)
					v[j].se -= sz;
				if (v[i].fi == v[i - 1].fi) {
					v.erase(v.begin() + i);
					i--;
				}
			}
		}
		for (int i = 1; i < v.size(); i++) {
			int sz = v[i].se - v[i - 1].se;
			while (sz--)
				ans.push_back(v[i-1].fi);
		}
		int sz = n - v.back().se + 1;
		while (sz--)
			ans.push_back(v.back().fi);
		cout << ans.size() << '\n';
		for (auto x : ans)
			cout << x << '\n';
	}
}