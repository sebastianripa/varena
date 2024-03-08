#include <fstream>
#include <map>
#include <vector>

using namespace std;

ifstream cin("traseu.in");
ofstream cout("traseu.out");

#define x first.first
#define y first.second
#define z second
#define point pair <pair<int, int>, int>

int dx, dy, dz;
point in, fn;
map <point, bool> mp;
vector <point> ans;

void afisare() {
	for (auto a : ans)
		cout << a.x << ' ' << a.y << ' ' << a.z << '\n';
	exit(0);
}

void dfs(point poz) {
	ans.push_back(poz);
	if (mp[poz])
		return;
	if (poz == fn)
		afisare();
	if (poz.x != fn.x && dx == -1) {
		poz.x += dx;
		dfs(poz);
		ans.pop_back();
		poz.x -= dx;
	}
	if (poz.y != fn.y && dy == -1) {
		poz.y += dy;
		dfs(poz);
		ans.pop_back();
		poz.y -= dy;
	}
	if (poz.z != fn.z && dz == -1) {
		poz.z += dz;
		dfs(poz);
		ans.pop_back();
		poz.z -= dz;
	}
	if (poz.z != fn.z && dz == 1) {
		poz.z += dz;
		dfs(poz);
		ans.pop_back();
		poz.z -= dz;
	}
	if (poz.y != fn.y && dy == 1) {
		poz.y += dy;
		dfs(poz);
		ans.pop_back();
		poz.y -= dy;
	}
	if (poz.x != fn.x && dx == 1) {
		poz.x += dx;
		dfs(poz);
		ans.pop_back();
		poz.x -= dx;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	cin >> in.x >> in.y >> in.z >> fn.x >> fn.y >> fn.z;
	dx = (in.x > fn.x) ? -1 : 1;
	dy = (in.y > fn.y) ? -1 : 1;
	dz = (in.z > fn.z) ? -1 : 1;
	while (m--) {
		point a;
		cin >> a.x >> a.y >> a.z;
		mp[a] = 1;
	}
	cout << abs(in.x - fn.x) + abs(in.y - fn.y) + abs(in.z - fn.z) + 1 << '\n';
	dfs(in);
}