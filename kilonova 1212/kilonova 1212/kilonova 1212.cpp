#include <fstream>
#include <cmath>
#define int long long

using namespace std;

ifstream cin("seceta.in");
ofstream cout("seceta.out");

struct point {
	int x, y;
};

int vf[13];
float s = 0.0, ans = 21e8;
point v1[13], v2[13];

//sqrt{(x_C-x_B)^2+(y_C-y_B)^2}

void bkt(int n, int pz) {
	if (pz == n + 1) {
		ans = min(ans, s);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!vf[i]) {
			s += (double)(sqrt((v2[i].x - v1[pz].x) * (v2[i].x - v1[pz].x) + (v2[i].y - v1[pz].y) * (v2[i].y - v1[pz].y)));
			vf[i] = 1;
			bkt(n, pz + 1);
			vf[i] = 0;
			s -= (double)(sqrt((v2[i].x - v1[pz].x) * (v2[i].x - v1[pz].x) + (v2[i].y - v1[pz].y) * (v2[i].y - v1[pz].y)));
		}
	}
}

signed main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> v1[i].x >> v1[i].y;
	for (int i = 1; i <= n; i++)
		cin >> v2[i].x >> v2[i].y;
	bkt(n, 1);
	cout << (int)(ans * 100);
}