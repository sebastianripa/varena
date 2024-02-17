#include <fstream>

using namespace std;

ifstream cin("sminus.in");
ofstream cout("sminus.out");

int v[100005];

int main() {
	int n;
	cin >> n;
	int s = -1, in = 0, st = 1, fn = 1, sm = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		v[i] = x;
		if (s < 0)
			s = 0, in = i;
		s += x;
		if (sm < s)
			sm = s, st = in, fn = i;
	}
	sm = 0;
	for (int i = 1; i <= n; i++) {
		if (i >= st && i <= fn)
			v[i] = -v[i];
		sm += v[i];
	}
	cout << st << ' ' << fn << '\n';
	cout << sm;
}