#include <iostream>
#define f first
#define s second

using namespace std;

pair <int, int> v[1005];
int mini[1005];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		v[i] = make_pair(n1, n2);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int temp3;
		for (int j = i+1; j <= n; j++) {
			int temp1 = max(v[i].f, v[j].f) - min(v[i].f, v[j].f);
			int temp2 = max(v[i].s, v[j].s) - min(v[i].s, v[j].s);
			temp3 = min(mini[i], temp1 + temp2);
		}
		ans = max(ans, temp3);
	}
	cout << ans * ans + 1;
}