#include <fstream>
#include <vector>
#include <map>

using namespace std;

ifstream cin("omogene.in");
ofstream cout("omogene.out");

struct trei {
	int c0, c1, c2;
};

int main() {
	int n, m;
	cin >> n >> m;
	vector <vector<int>> a(n + 1, vector<int>(m + 1));
	vector <vector<trei>> sum(n + 1, vector<trei>(m + 1, {0, 0, 0}));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			sum[i][j].c0 = sum[i - 1][j].c0 + sum[i][j - 1].c0 - sum[i - 1][j - 1].c0 + (a[i][j] == 0);
			sum[i][j].c1 = sum[i - 1][j].c1 + sum[i][j - 1].c1 - sum[i - 1][j - 1].c1 + (a[i][j] == 1);
			sum[i][j].c2 = sum[i - 1][j].c2 + sum[i][j - 1].c2 - sum[i - 1][j - 1].c2 + (a[i][j] == 2);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			map <pair<int, int>, int> mp;
			mp[{0, 0}] = 1;
			for (int k = 1; k <= m; k++) {
				int s0 = sum[j][k].c0 - sum[i - 1][k].c0;
				int s1 = sum[j][k].c1 - sum[i - 1][k].c1;
				int s2 = sum[j][k].c2 - sum[i - 1][k].c2;
				ans += mp[{s0 - s1, s1 - s2}];
				mp[{s0 - s1, s1 - s2}]++;
			}
		}
	}
	cout << ans;
}