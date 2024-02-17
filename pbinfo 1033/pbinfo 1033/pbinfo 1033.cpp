#include <fstream>
#include <vector>

using namespace std;

ifstream cin("elicop.in");
ofstream cout("elicop.out");

int m[105][105], sp[105][105];
vector <int> v;

int main() {
	int n, m1;
	cin >> n >> m1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m1; j++) {
			cin >> m[i][j];
			sp[i][j] = sp[i][j - 1] + m[i][j];
		}
	}
	int k, cnt = 1, nrm = 0;
	cin >> k;
	while (k--) {
		int a1, b1, a2, b2, d;
		cin >> a1 >> b1 >> a2 >> b2 >> d;
		if (a2 < a1) {
			swap(a1, a2);
			swap(b1, b2);
		}
		if (b2 < b1) {
			int sm = 0, sr = 0;
			for (int i = a2, j = b2; i >= a1; i--, j++) {
				sm += i - a1 + 1;
				if (d == 1)
					sr += sp[i][j] - sp[i][b2 - 1];
				else
					sr += sp[i][b1] - sp[i][j - 1];
			}
			if (sm - sr > sr)
				v.push_back(cnt);
			if (sm == sr)
				nrm++;
		}
		else {
			int sm = 0, sr = 0;
			for (int i = a2, j = b2; i >= a1; i--, j--) {
				sm += i - a1 + 1;
				if (d == 1)
					sr += sp[i][b2] - sp[i][j - 1];
				else
					sr += sp[i][j] - sp[i][b1 - 1];
			}
			if (sm - sr > sr)
				v.push_back(cnt);
			if (sm == sr)
				nrm++;
		}
		cnt++;
	}
	cout << nrm << '\n' << v.size();
	for (auto x : v)
		cout << ' ' << x;
}