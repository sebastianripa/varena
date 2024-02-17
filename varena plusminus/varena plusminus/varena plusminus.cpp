#include <fstream>
#include <vector>

using namespace std;

ifstream cin("valutar.in");
ofstream cout("valutar.out");

struct casa {
	char a;
	int l, e;
};

struct jucator {
	int j, p, l, e;
};

vector <jucator> v;
int vp[105];
casa c[10005];

int main() {
	int cer, a, b, nr, n, m, l, e, nrm;
	cin >> cer >> a >> b >> nr >> n >> m >> l >> e >> nrm;
	for (int i = 1; i <= m; i++) {
		v.push_back({ i, 1, l, e });
	}
	for (int i = 1; i <= n; i++)
		cin >> c[i].a >> c[i].l >> c[i].e;
	int i = -1;
	while (nrm--) {
		i++;
		nr = (a * nr + b) % n + 1;
		if (i >= v.size())
			i = 0;
		v[i].p += nr;
		if(v[i].p > n)
			v[i].p %= n;
		if (c[v[i].p].a == 'G') {
				int cst = c[v[i].p].l * v[i].p;
			if (cst > v[i].l) {
				if (!vp[v[i].j])
					v.erase(v.begin() + i);
				else
					vp[v[i].j]--;
				continue;
			}
			v[i].l -= cst;
			v[i].e += v[i].p;
			continue;
		}
		if (c[v[i].p].a == 'V') {
			if (v[i].p > v[i].e) {
				if (!vp[v[i].j])
					v.erase(v.begin() + i);
				else
					vp[v[i].j]--;
				continue;
			}
			v[i].e -= v[i].p;
			v[i].l += (i * c[v[i].p].e);
			continue;
		}
		else if (c[v[i].p].a == 'R')
			vp[v[i].j]++;
	}
	if (cer == 1)
		cout << v.size();
	else
		cout << v[0].j;
}