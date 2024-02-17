#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

ifstream cin("seti.in");
ofstream cout("seti.out");

int mp[123];
string v[200005];

bool cmp(string a, string b) {
	for (int i = 0; i < min(a.size(), b.size()); i++) {
		if (a[i] != b[i])
			return mp[a[i]] < mp[b[i]];
	}
	return a.size() < b.size();
}

int main() {
	int n = 10;
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		mp[c] = i;
	}
	string s;
	int i = 0;
	while (cin >> s)
		v[i++] = s;
	sort(v, v + i, cmp);
	for (string x : v)
		cout << x << '\n';
}