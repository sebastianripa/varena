#include <fstream>
#include <map>
#include <list>

using namespace std;

ifstream cin("criptografie.in");
ofstream cout("criptografie.out");

map <char, int> mp;
map <list <char>, int> mp1;
list <char> q;

int main() {
	long long cer, k, n;
	cin >> cer >> k >> n;
	if (cer == 1) {
		string s;
		cin >> s;
		long long l = 0, r = 0, ans = 0;
		while (r < n) {
			if (mp[s[r]] == k) {
				mp[s[l]]--;
				l++;
				continue;
			}
			ans += r - l + 1;
			mp[s[r]]++;
			r++;
		}
		cout << ans;
	}
	else {
		long long l = 0, r = 0, sm = 0;
		string s;
		cin >> s;
		while (l < n) {
			if (mp[s[r]] || r == n) {
				mp[s[l]]--;
				q.pop_front();
				l++;
				if (!mp[s[r]] && q.size() >= sm) {
					if (q.size() > sm) {
						sm = q.size();
						mp1.clear();
					}
					mp1[q]++;
				}
				continue;
			}
			mp[s[r]]++;
			q.push_back(s[r]);
			if (q.size() >= sm) {
				if (q.size() > sm) {
					sm = q.size();
					mp1.clear();
				}
				mp1[q]++;
			}
			r++;
		}
		for (auto x : mp1) {
			for (auto y : x.first)
				cout << y;
			break;
		}
	}
}