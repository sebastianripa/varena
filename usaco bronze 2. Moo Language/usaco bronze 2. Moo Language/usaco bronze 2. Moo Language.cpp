#include <iostream>
#include <vector>
#include <map>

using namespace std;

map <string, vector<string>> mp;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int  n, c, p;
		cin >> n >> c >> p;
		for (int i = 1; i <= n; i++) {
			string  s1, s2;
			cin >> s1 >> s2;
			mp[s2].push_back(s1);
		}
		int rn = mp["nouns"].size() - (mp["transitive-verb"].size() * 2 + mp["intransitive-verb"].size());
		if (rn < 0)
			rn = 0;
		if (rn == 0) {
			int mxp = mp["transitive-verb"].size() + mp["intransitive-verb"].size(), nrn = mp["nouns"].size(), i1 = 0, i2 = 0, i3 = 0;
			while (c || mxp || nrn) {
				if (nrn >= 2) {
					
				}
			}
		}
	}
}