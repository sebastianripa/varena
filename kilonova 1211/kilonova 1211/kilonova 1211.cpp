#include <iostream>

using namespace std;

//ifstream cin("romeo.in");
//ofstream cout("romeo.out");

int main() {
	int n, m;
	cin >> n >> m;
	if (m >= n || n - m == 1)
		cout << n + m, exit(0);
	int dif = n / m;
	int ans = dif * (dif + 1) / 2 * n;
	ans += (dif + 1) * (n % m);
	cout << ans;
}