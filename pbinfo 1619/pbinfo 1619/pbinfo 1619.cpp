#include <fstream>

using namespace std;

ifstream cin("pic.in");
ofstream cout("pic.out");

int main() {
	int cer, n;
	cin >> cer >> n;
	if (cer == 1) {
		int nr = 1, s = 0, maxi = 0, lvl = 1;
		n = n * (n + 1) / 2;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			s += x;
			if (nr * (nr + 1) / 2 == i) {
				if (maxi < s) {
					maxi = s;
					lvl = nr;
				}
				nr++;
				s = 0;
			}
		}
		cout << lvl;
	}
}