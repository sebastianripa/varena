#include <iostream>

using namespace std;

int dir[] = { 1, -1 };

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int xk, yk, xq, yq;
		cin >> xk >> yk >> xq >> yq;
		int xc, yc, ans = 0;
		for (int i = 1; i <= 4; i++) {
			if (i <= 2)
				xc = xk + dir[i % 2] * a;
			else
				yc = yk + dir[i % 2] * a;
			for (int j = 1; j <= 2; j++) {
				if (i <= 2)
					yc = yk + dir[j - 1] * b;
				else
					xc = xk + dir[j - 1] * b;
				int xp, yp;
				for (int i = 1; i <= 4; i++) {
					if (i <= 2)
						xp = xc + dir[i % 2] * a;
					else
						yp = yc + dir[i % 2] * a;
					for (int j = 1; j <= 2; j++) {
						if (i <= 2)
							yp = yc + dir[j - 1] * b;
						else
							xp = xc + dir[j - 1] * b;
						if (xp == xq && yp == yq)
							ans++;
					}
				}
			}
		}
		if (a == b)
			ans /= 4;
		cout << ans << '\n';
	}
}