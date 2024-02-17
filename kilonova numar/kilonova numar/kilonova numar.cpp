#include <fstream>

using namespace std;

ifstream cin("numar.in");
ofstream cout("numar.out");

bool v[10];

int main() {
	int n, ogx;
	cin >> n >> ogx;
	int s = ogx;
	for (int i = 2; i <= n; i++) {
		int x;
		cin >> x;
		if (ogx <= x)
			s += x;
		else {
			if (s % 9 == 0 && s != 0)
				v[9] = 1;
			else
				v[s % 9] = 1;
			s = x;
		}
		ogx = x;
	}
	if (s % 9 == 0 && s != 0)
		v[9] = 1;
	else
		v[s % 9] = 1;
	bool ok = 0;
	for (int i = 9; i >= 0; i--)
		if (!v[i])
			cout << i, ok = 1;
	if (!ok)
		cout << -1;
}