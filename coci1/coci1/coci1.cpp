#include <iostream>
#include <vector>

using namespace std;

string names[55];
vector <vector<int>> m[50];

int main() {
	int n;
	cin >> n;
	for (int k = 1; k <= n; k++) {
		cin >> names[k];
		m[k].resize(6);
		for (int i = 1; i <= 5; i++) {
			m[k][i].resize(6);
			for (int j = 1; j <= 5; j++)
				cin >> m[k][i][j];
		}
	}
	int q;
	cin >> q;
	if (q < 5)
		cout << 0, exit(0);
	while (q--) {
		int x;
		cin >> x;

	}
}