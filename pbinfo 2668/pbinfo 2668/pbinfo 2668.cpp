#include <iostream>
#include <vector>

using namespace std;

int v[3][100005];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= 3*n; i++) {
		if (!(i % n))
			cin >> v[i / n - 1][n];
		else
			cin >> v[i / n][i%n];
	}
	int i = 1, j = 1, k = 1;
	while (i <= n && j <= n && k <= n) {
		if (v[0][i] < v[1][j])
			i++;
		if (v[1][j] < v[2][k])
			j++;
		if (v[2][k] < v[0][i])
			k++;
		if (v[0][i] == v[1][j] && v[1][j] == v[2][k])
			cout << v[0][i], exit(0);
	}
	cout << -1;
}