#include <fstream>

using namespace std;

ifstream cin("masina.in");
ofstream cout("masina.out");

int v[30005];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	int s = 0, sm = 0, pz = 1, pzf = -1, smin = 0, sminm = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (v[i] - x < 0) {
			if (sm <= s)
				sm = s, pzf = pz;
			s = 0;
			smin += v[i] - x;
			pz = i + 1;
		}
		else {
			sminm = min(smin, sminm);
			smin = 0;
			s += v[i] - x;
		}
	}
	if (sm <= s)
		sm = s, pzf = pz;
	sminm = min(smin, sminm);
	s = 0;
	if(sm > -sminm)
		cout << pzf;
}