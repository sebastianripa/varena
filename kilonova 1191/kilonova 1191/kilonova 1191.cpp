#include <fstream>
#include <algorithm>

using namespace std;

ifstream cin("snipers.in");
ofstream cout("snipers.out");

struct point {
	int x, y, idx;
};

point v1[200], v2[200];
int ans[200];

bool cmp(point a, point b) {
	if (a.y != b.y)
		return a.y < b.y;
	return a.x > b.x;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> v1[i].x >> v1[i].y, v1[i].idx = i;
	for (int i = 1; i <= n; i++)
		cin >> v2[i].x >> v2[i].y, v2[i].idx = i;
	sort(v1 + 1, v1 + n + 1, cmp);
	sort(v2 + 1, v2 + n + 1, cmp);
	for (int i = 1; i <= n; i++)
		ans[v1[i].idx] = v2[i].idx;
	for (int i = 1; i <= n; i++)
		cout << ans[i] << '\n';
}