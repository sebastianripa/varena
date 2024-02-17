#include <fstream>
#include <algorithm>

using namespace std;

ifstream cin("lemonade.in");
ofstream cout("lemonade.out");

int v[100005];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	sort(v + 1, v + n + 1);
	int ans = 0;
	for (int i = n; i >= 1; i--) {
		if (ans <= v[i])
			ans++;
	}
	cout << ans;
}