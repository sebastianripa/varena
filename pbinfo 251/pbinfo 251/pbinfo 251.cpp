#include <fstream>

using namespace std;

ifstream cin("interclasare2.in");
ofstream cout("interclasare2.out");

bool vf[1000001];

int main() {
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		vf[x] = 1;
	}
	cin >> m;
	int nra = 0;
	for (int i = 1; i <= m; i++) {
		int x;
		cin >> x;
		if (vf[x])
			cout << x << ' ', nra++;
		if (nra == 10)
			cout << '\n', nra = 0;
	}
}