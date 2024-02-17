#include <fstream>
#define int unsigned long long

using namespace std;

ifstream cin("7segmente.in");
ofstream cout("7segmente.out");

int v[] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

int putere(string n) {
	int ans = 0;
	for (int i = 0; i < n.size(); i++)
		ans += v[n[i] - '0'];
	return ans;
}

signed main() {
	int p;
	string n;
	cin >> n >> p;
	cout << putere(n) << ' ';
	
}