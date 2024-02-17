#include <fstream>
#include <map>
#include <cmath>

using namespace std;

ifstream cin("ec.in");
ofstream cout("ec.out");

map <float, bool> vf;

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			vf[x] = 1;
		}
	}
	int ans1 = 0, anst1 = 0, ans2 = 0, anst2 = 0;
	while (k--) {
		string s;
		cin >> s;
		int i = 0, nr1 = 0, semn = 1;
		if (s[i] == '-')
			semn = -1;
		for (; s[i] != 'x'; i++)
			nr1 = nr1 * 10 + (s[i] - '0');
		nr1 *= semn;
		semn = 1;
		bool g2 = 0, ch = 0;
		if (s[i + 1] == '^')
			g2 = 1;
		if (g2 == 1 && nr1 == 0) {
			ch = 1;
			i += 2;
			if (s[i] == '-')
				semn = -1;
			i++;
			for (; s[i] != 'x'; i++)
				nr1 = nr1 * 10 + (s[i] - '0');
			nr1 *= semn;
			semn = 1;
			g2 = 0;
		}
		if (!g2) {
			if (nr1 == 0) {
				if (!ch)
					ans1++, anst1++;
				else ans2++, anst2++;
				continue;
			}
			if (!ch)
				ans1++;
			else ans2++;
			if (s[i + 1] == '-')
				semn = -1;
			i += 2;
			int nr2 = 0;
			for (; s[i] != '='; i++)
				nr2 = nr2 * 10 + (s[i] - '0');
			nr2 *= semn;
			semn = 1;
			if (s[i + 1] == '-')
				semn = -1, i++;
			i++;
			int nr3 = 0;
			for (; i < s.size(); i++)
				nr3 = nr3 * 10 + (s[i] - '0');
			nr3 *= semn;
			float x = (float)(nr3 - nr2) / (float)nr1;
			if (vf[x]) {
				if (!ch)
					anst1++;
				else anst2++;
			}
			continue;
		}
		ans2++;
		i += 3;
		if (s[i] == '-')
			semn = -1;
		i++;
		int nr2 = 0;
		for (; s[i] != 'x'; i++)
			nr2 = nr2 * 10 + (s[i] - '0');
		i++;
		nr2 *= semn;
		semn = 1;
		int nr3 = 0;
		if (s[i] == '-')
			semn = -1;
		i++;
		for (; s[i] != '='; i++)
			nr3 = nr3 * 10 + (s[i] - '0');
		i++;
		nr3 *= semn;
		semn = 1;
		if (s[i] == '-')
			semn = -1, i++;
		int nr4 = 0;
		for (; i < s.size(); i++)
			nr4 = nr4 * 10 + (s[i] - '0');
		nr4 *= semn;
		nr3 -= nr4;
		int delta = nr2 * nr2 - 4 * nr1 * nr3;
		if (delta < 0)
			continue;
		float x1 = (float)(-nr2 + sqrt(delta)) / (float)(2 * nr1);
		float x2 = (float)(-nr2 - sqrt(delta)) / (float)(2 * nr1);
		if (vf[x1] && vf[x2])
			anst2++;
	}
	cout << ans1 << ' ' << anst1 << '\n' << ans2 << ' ' << anst2;
}