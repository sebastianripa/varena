#include <fstream>
#include <vector>
#include <map>

using namespace std;

ifstream cin("aproape.in");
ofstream cout("aproape.out");

vector <int> v;
map <double, bool> mp;

int main() {
	int cer, n;
	cin >> cer >> n;
	if (cer == 1) {
		int nrc = 0;
		if (n == 0)
			nrc++;
		while (n) {
			nrc++;
			n /= 10;
		}
		cout << nrc;
	}
	else if (cer == 2) {
		int nra = 0;
		if (n % 10 == n) {
			if (n % 10 - 1 >= 0)
				nra++;
			if (n % 10 + 1 <= 9)
				nra++;
			n /= 10;
		}
		while (n) {
			if (n % 10 - 1 > 0)
				nra++;
			else if (n % 10 - 1 == 0 && n / 10)
				nra++;
			if (n % 10 + 1 <= 9)
				nra++;
			n /= 10;
		}
		cout << nra;
	}
	else {
		int cn = n, p = 1, ans = 0;
		if (cn % 10 == n) {
			if (cn % 10 - 1 >= 0)
				v.push_back(n - p), mp[(double)(n - p) / 1000] = 1;
			if (cn % 10 + 1 <= 9)
				v.push_back(n + p), mp[(double)(n + p) / 1000] = 1;
			cn /= 10;
		}
		while (cn) {
			if (cn % 10 - 1 > 0)
				v.push_back(n - p), mp[(double)(n - p) / 1000] = 1;
			else if (cn % 10 - 1 == 0 && cn / 10)
				v.push_back(n - p), mp[(double)(n - p) / 1000] = 1;
			if (cn % 10 + 1 <= 9)
				v.push_back(n + p), mp[(double)(n + p) / 1000] = 1;
			cn /= 10;
			p *= 10;
		}
		for (int i = 0; i < v.size(); i++) {
			int p = 1, nr = v[i];
			if (v[i] % 10 == v[i]) {
				if (v[i] % 10 - 1 >= 0 && !mp[(double)(nr - p) / 1000])
					ans++, mp[(double)(nr - p) / 1000] = 1;
				if (v[i] % 10 + 1 <= 9 && !mp[(double)(nr + p) / 1000])
					ans++, mp[(double)(nr + p) / 1000] = 1;
				v[i] /= 10;
			}
			while (v[i]) {
				if (v[i] % 10 - 1 > 0 && !mp[(double)(nr - p) / 1000])
					ans++, mp[(double)(nr - p) / 1000] = 1;
				else if (v[i] % 10 - 1 == 0 && v[i] / 10 && !mp[(double)(nr - p) / 1000])
					ans++, mp[(double)(nr - p) / 1000] = 1;
				if (v[i] % 10 + 1 <= 9 && !mp[(double)(nr + p) / 1000])
					ans++, mp[(double)(nr + p) / 1000] = 1;
				p *= 10;
				v[i] /= 10;
			}
		}
		cout << ans;
	}
}