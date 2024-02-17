#include <fstream>
#include <list>
#include <map>

using namespace std;

ifstream cin("teatru.in");
ofstream cout("teatru.out");

string s;
map <char, int> mp;

int main() {
	int n, nrd;
	cin >> n >> nrd >> s;
	int l = 0, r = 0, lm = 0, nd = 0, lf, rf;
	while (l < n) {
		if (r == n || nd <= nrd) {
			if (lm < r - l) {
				lm = r - l;
				lf = l;
				rf = r - 1;
			}
		}
		if (nd > nrd || r == n) {
			mp[s[l]]--;
			if (!mp[s[l]])
				nd--;
			l++;
			continue;
		}
		if (!mp[s[r]])
			nd++;
		mp[s[r]]++;
		r++;
	}
	cout << lm << '\n';
	for (int i = lf; i <= rf; i++)
		cout << s[i];
}