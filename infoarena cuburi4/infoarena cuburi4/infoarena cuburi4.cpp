#include <fstream>
#include <map>

using namespace std;

ifstream cin("cuburi4.in");
ofstream cout("cuburi4.out");

map <string, int> mp1, mp2;
int ans;

void mere(char s, char d, char S, char D, int i) {
	if (d < s) swap(s, d);
	if (D < S) swap(S, D);
	if (s > S || (s == S && d > D)) { swap(s, S); swap(D, d); }
	string s1;
	s1 = s1 + s + d + S + D;
	if (mp1[s1] != i) ans = max(ans, ++mp2[s1]);
	mp1[s1] = i;
}

int main() {
	int n, i;
	cin >> n;
	string s;
	for (i = 1; i <= n; i++) {
		string s;
		cin >> s;
		mere(s[2], s[4], s[3], s[5], i);
		mere(s[0], s[1], s[3], s[5], i);
		mere(s[0], s[1], s[2], s[4], i);
	}
	cout << ans;
}