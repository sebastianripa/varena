#include <fstream>
#include <cmath>

using namespace std;

ifstream cin("plimbare.in");
ofstream cout("plimbare.out");

bool vf[24];

int main() {
	int n, nr, s = 0;
	cin >> n >> nr;
	for (int i = 0; i < n; i++)
		s += (1 << i);
	//bkt(n - 1, 0, 0);
	int dif = s - nr;
	while (dif) {
		int x = log2(dif & -dif) - 1;
		cout << x << " -\n";
		vf[x] = 1;
		dif -= (dif & -dif);
	}
	for (int i = 0; i < n; i++) {
		if (!vf[i])
			cout << i << " +\n";
	}
}