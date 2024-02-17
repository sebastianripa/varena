#include <iostream>
#include <vector>

using namespace std;

char s[1000005];
vector <pair<int, int>> ans;

int main() {
	int n;
	cin >> n;
	int nrd = 0, nri = 0;

	for (int i = 1; i <= n; i++)
		cin >> s[i];
	nrd = 0, nri = 0;
	int j = n;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '(')
			nrd++;
		else
			nri++;
		if (nri > nrd) {
			for (; s[j] != '('; j--)
				continue;
			ans.push_back({ i, j });
			j--;
			nri--;
			nrd++;
		}
	}
	cout << ans.size() << '\n';
	for (auto x : ans)
		cout << x.first - 1 << ' ' << x.second - 1 << '\n';
}