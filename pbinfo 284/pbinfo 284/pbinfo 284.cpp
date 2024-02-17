#include <fstream>
#include <set>

using namespace std;

ifstream cin("interclasare3.in");
ofstream cout("interclasare3.out");

multiset <int> s;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if(x%2 == 0)
			s.insert(x);
	}
	for (int i = 1; i <= m; i++) {
		int x;
		cin >> x;
		if(x%2 == 0)
			s.insert(x);
	}
	int nra = 0;
	for (auto x : s) {
		nra++;
		cout << x << ' ';
		if (nra == 20)
			cout << '\n', nra = 0;
	}
}