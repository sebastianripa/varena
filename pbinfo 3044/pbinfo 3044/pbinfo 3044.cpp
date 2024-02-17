#include <fstream>
#include <vector>

using namespace std;

ifstream cin("comun.in");
ofstream cout("comun.out");

bool vf[100005];
vector <int> ans;

int cmmdc(int a, int b) {
	int r = a % b;
	while (r) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

void solve(int mx) {
	for (int i = 1; i <= mx; i++) {
		if (vf[i]) {
			int dc = 0;
			for (int j = i * 2; j <= mx; j += i)
				if (vf[j]) {
					if (dc == 0)
						dc = j;
					dc = cmmdc(dc, j);
				}
			if (dc != i)
				ans.push_back(i);
		}
	}
	cout << ans.size() << '\n';
	for (auto x : ans)
		cout << x << ' ';
}

int main() {
	int n;
	cin >> n;
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		mx = max(mx, x);
		vf[x] = 1;
	}
	solve(mx);
}