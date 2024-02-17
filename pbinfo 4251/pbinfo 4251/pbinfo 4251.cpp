#include <fstream>
#include <vector>

using namespace std;

ifstream cin("numereoji.in");
ofstream cout("numereoji.out");

int v[15], n = 10, s1 = 0, s2 = 0, ans = 0, maxi = 0;
vector <int> v1, v2, c1, c2;

void bkt(int pz) {
	if (pz == n + 1) {
		if (s1 == s2) {
			if (!s1)
				return;
			ans++;
			if (maxi < s1) {
				maxi = s1;
				c1 = v1;
				c2 = v2;
			}
		}
		return;
	}
	s1 += v[pz];
	v1.push_back(v[pz]);
	bkt(pz + 1);
	v1.pop_back();
	s1 -= v[pz];
	s2 += v[pz];
	v2.push_back(v[pz]);
	bkt(pz + 1);
	v2.pop_back();
	s2 -= v[pz];
	bkt(pz + 1);
}

int main() {
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	bkt(1);
	cout << ans/2 << ' ' << maxi << '\n';
	for (auto x : c1)
		cout << x << ' ';
	cout << '\n';
	for (auto x : c2)
		cout << x << ' ';
}