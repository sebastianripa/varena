#include <fstream>

using namespace std;

ifstream cin("tramvaie.in");
ofstream cout("tramvaie.out");

int v[1000010], v1[1000010];

int main() {
	int n;
	cin >> n;
	int maxi = 0;
	for (int i = 1; i <= n; i++) {
		cin >> v1[i];
		maxi = max(maxi, v1[i]);
	}
	for (int i = 1; i <= maxi; i++)
		v[i] = i;
	for (int i = 2; i <= maxi; i++) {
		if (v[i] == i) {
			v[i]--;
			for (int j = 2 * i; j <= maxi; j += i)
				v[j] = v[j] / i * (i - 1);
		}
	}
	for (int i = 1; i <= n; i++)
		cout << v[v1[i]] << ' ';
}