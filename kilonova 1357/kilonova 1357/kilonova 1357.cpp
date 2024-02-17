#include <fstream>
#include <map>

using namespace std;

ifstream cin("ape.in");
ofstream cout("ape.out");

char v[10005];
map <int, int> mp;

int main() {
	int n;
	cin >> n;
	int cnt[2] = { 0, 0 }, cntm[2] = { 0, 0 }, sens = 0, nrv = 0, nrn = 0;
	char current[2] = { 1, 1 };
	for (int i = 1; i <= n; i++) {
		//citire
		cin >> v[i];
		
		//cerinta 3
		if (v[i] == 'V')
			nrv++;
		//cerinta 1 si 2
		if (current[1] != v[i] && v[i] != 'N' && v[i] != 'S') {
			current[1] = v[i];
			cntm[1] = max(cntm[1], cnt[1]);
			cnt[1] = 0;
		}
		if (current[0] != v[i] && v[i] != 'E' && v[i] != 'V') {
			current[0] = v[i];
			cntm[0] = max(cntm[0], cnt[0]);
			cnt[0] = 0;
		}
		if (v[i] == 'N' || v[i] == 'S')
			cnt[0]++;
		else
			cnt[1]++;
	}
	cntm[1] = max(cntm[1], cnt[1]);
	cntm[0] = max(cntm[0], cnt[0]);
	cout << cntm[1] - 1 << ' ' << cntm[0] - 1 << ' ';
	int nrpc[4] = { 0, 0, 0, 0 };
	int ok = 0;
	for (int i = 1; i <= n; i++) {
		if (v[i] == 'E')
			nrpc[1]++;
		else if(v[i] == 'V') nrpc[3]++;
		if (ok && ok < 3) {
			if (ok == 1) {
				if (v[i] == 'N')
					sens = 1;
			}
			else if (v[i] == 'S')
				sens = 1;
			ok = 3;
		}
		if (!ok && nrpc[1] == nrv)
			ok = 1;
		if (!ok && nrpc[3] == nrv)
			ok = 2;
		
	}
	cout << sens << ' ';
	int x = 0, y = 0, a = 0;
	for (int i = 1; i <= n; i++) {
		if (v[i] == 'N') {
			mp[x] = 21e8;
			x--;
			continue;
		}
		if (v[i] == 'S') {
			mp[x] = 21e8;
			x++;
			continue;
		}
	}
	int ok1 = 0;
	bool sj = 0, schimb = 0;
	for (int i = 1; i <= n; i++) {
		if (v[i] == 'V') {
			y--;
			mp[x] = y;
			schimb = 1;
			continue;
		}
		if (v[i] == 'E') {
			if (!ok1) {
				if (mp[x] == 21e8)
					mp[x] = y, ok1 = 2;
				else ok1 = 1;
			}
			y++;
			continue;
		}
		if (v[i] == 'N' || v[i] == 'S') {
			if (v[i] == 'N')
				cout << "";
			if (mp[x] == 21e8)
				mp[x] = y;
			else if (sj && ok1 < 2 && !schimb) {
				a += mp[x] - y - 1;
				mp[x] = 21e8;
			}
			sj = 1;
			if (v[i] == 'N')
				x--;
			else
				x++;
		}
		ok1 = 0;
		schimb = 0;
	}
	cout << a;
}