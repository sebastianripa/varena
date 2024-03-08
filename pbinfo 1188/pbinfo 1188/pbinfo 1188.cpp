#include <iostream>
#include <vector>

using namespace std;

pair <int, int> v[100005];
vector <vector<int>> a;

int main() {
	int cer;
	cin >> cer;
	if (cer == 1) {
		int n;
		cin >> n;
		int r = 1, c = 1;
		pair <int, int> rm, cm;
		for (int i = 2; i <= n + 1; i++) {
			char d;
			int c;
			cin >> c >> d;
			v[i] = v[c];
			if (d == 'N')
				v[i].first--;
			if (d == 'E')
				v[i].second++;
			if (d == 'S')
				v[i].first++;
			if (d == 'V')
				v[i].second--;
			rm.first = min(rm.first, v[i].first);
			rm.second = max(rm.second, v[i].first);
			cm.first = min(cm.first, v[i].second);
			cm.second = max(cm.second, v[i].second);
		}
		int dr = 1 - rm.first, dc = 1 - cm.first;
	}
	else {
		int n, m;
		cin >> n >> m;
		a.resize(n + 2);
		a[0].resize(m + 1);
		a[n + 1].resize(m + 1);
		int nrc = 0;
		for (int i = 1; i <= n; i++) {
			a[i].resize(m + 1);
			for (int j = 1; j <= m; j++) {
				cin >> a[i][j];
				if (a[i][j])
					a[i][j] += nrc, nrc++;
			}
		}
		cout << nrc << ' ' << 1 << '\n';
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (i == 1 && j == 1)
					continue;
				if (a[i][j]) {
					if (a[i][j - 1])
						cout << a[i][j - 1] << " E\n";
					else if (a[i + 1][j])
						cout << a[i + 1][j] << " N\n";
					else if (a[i - 1][j])
						cout << a[i - 1][j] << " S\n";
					else cout << a[i][j + 1] << " V\n";
				}
			}
		}
	}
}