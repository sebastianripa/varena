#include <fstream>

using namespace std;

ifstream cin("cod.in");
ofstream cout("cod.out");

bool vf[200];

int main() {
	string s;
	cin >> s;
	int n = s.size(), i;
	for (i = 0; i < n; i++) {
		if (vf[s[i]])
			break;
		vf[s[i]] = 1;
	}
	if (i < n)
		cout << 0, exit(0);
	if (n == 1)
		cout << (int)s[0] - 'a' + 1, exit(0);
	int ansf = nrsm(n - 1);

}