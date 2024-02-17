#include <fstream>

using namespace std;

ifstream cin("secvmaxval.in");
ofstream cout("secvmaxval.out");

int v[200005];

int main() {
	unsigned long long n, sc;
	cin >> n >> sc;
	for (unsigned long long i = 1; i <= n; i++)
		cin >> v[i];
	unsigned long long s = 0;
	unsigned long long l = 1, r = 1, lm = 0;
	while (r <= n) {
		if (s > sc) {
			s -= v[l];
			l++;
		}
		s += v[r];
		r++;
		if (s <= sc && lm < r - l)
			lm = r - l;
	}
	if (s <= sc && lm < r - l)
		lm = r - l;
	cout << lm;
}