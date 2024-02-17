#include <fstream>
#include <list>
#include <cmath>

using namespace std;

ifstream cin("memory006.in");
ofstream cout("memory006.out");

list <int16_t> v;

int main() {
	long long n, ans = 0;
	int16_t sc, s = 0;
	cin >> n >> sc;
	for (int i = 1; i <= n; i++) {
		long long x;
		cin >> x;
		while (s > sc) {
			s -= v.front();
			v.pop_front();
		}
		if (s == sc)
			ans++;
		if ((x & -x) != x || log2(x) > sc) {
			s = 0;
			v.clear();
			continue;
		}
		x = log2(x);
		s += x;
		v.push_back(x);
	}
	if (s == sc)
		ans++;
	cout << ans;
}