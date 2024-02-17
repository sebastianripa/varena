#include <fstream>

using namespace std;

ifstream cin("sumainsecv.in");
ofstream cout("sumainsecv.out");

int v[105];

int main() {
	int n, sc;
	cin >> n >> sc;
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	int l = 1, r = 1, s = 0;
	bool afisat = false;
	while (r < n) {
		s += v[r];
		while (l < r && s > sc) {
			s -= v[l];
			l++;
		}
		if (sc == s) {
			cout << l << ' ' << r;
			afisat = true;
			break;
		}
		r++;
	}
	if (!afisat)
		cout << "0 0";
}