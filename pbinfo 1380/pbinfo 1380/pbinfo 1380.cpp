#include <fstream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

ifstream cin("pluton.in");
ofstream cout("pluton.out");

map <string, int> mp;
map <string, vector<string>> ms;

int main() {
	int n;
	cin >> n;
	int maxx = 0, nrm = 0;
	string nrim;
	for (int i = 1; i <= n; i++) {
		string s, s1;
		cin >> s;
		s1 = s;
		sort(s.begin(), s.end());
		mp[s]++;
		if (maxx < mp[s]) {
			maxx = mp[s];
			nrm = 1;
			nrim = s;
		}
		else if (maxx == mp[s])
			nrm++;
		ms[s].push_back(s1);
	}
	cout << mp.size() << '\n' << maxx << '\n' << nrm << '\n';
	for (auto x : ms[nrim]) {
		cout << x << ' ';
	}
}