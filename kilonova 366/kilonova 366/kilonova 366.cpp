#include <iostream>

using namespace std;

//ifstream cin("palindrom.in");
//ofstream cout("palindrom.out");

pair <int, int> vv[10];
int vs[10];

int schimbMax(int n) {
	int maxi = 0, np = n;
	if (vv[n].first != -1)
		return vv[vv[n].first].second;
	while (vs[n] != np) {
		vv[n].first = np;
		maxi = max(maxi, n);
		n = vs[n];
	}
	vv[n].first = np;
	maxi = max(maxi, n);
	vv[np].second = maxi;
	return maxi;
}

int main() {
	for (int i = 0; i <= 9; i++)
		cin >> vs[i], vv[i].first = -1;
	string s, sm;
	cin >> s;
	sm = s;
	int k;
	cin >> k;
	if (s.size() % 2) {
		for (int i = 0; i <= s.size() / 2; i++)
			sm[i] = schimbMax(sm[i] - '0') + '0';
		for (int i = s.size() / 2 + 1; i <= s.size(); i++)
			sm[i] = sm[s.size() - i - 1];
		cout << s;
	}
	else {
		for (int i = 0; i < s.size() / 2; i++)
			sm[i] = schimbMax(sm[i] - '0') + '0';
		for (int i = s.size() / 2; i < s.size(); i++)
			sm[i] = sm[s.size() - i - 1];
		cout << sm;
	}

}