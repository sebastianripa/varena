#include <fstream>
#include <map>

using namespace std;

ifstream cin("pentagon.in");
ofstream cout("pentagon.out");

char m[205][205];
map <int, int> mp;

int main() {
	int n, m1;
	cin >> n >> m1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m1; j++)
			cin >> m[j][i];
	}
	for (int i = 1; i <= m1; i++) {
		int nrz = 0;
		for (int j = 1; j <= n; j++) {
			if (!(m[i][j] - 48))
				nrz++;
			else {
				if(nrz)
					mp[nrz]++;
				nrz = 0;
			}
		}
		if (nrz)
			mp[nrz]++;
		nrz = 0;
	}
	for (auto x : mp)
		cout << x.first << ' ' << x.second << '\n';
}