#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//ifstream fin("test.in");

int v1[200005], v2[200005];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> v1[i] >> v2[i];
	sort(v1 + 1, v1 + n + 1);
	sort(v2 + 1, v2 + n + 1);
	int j = 1, ans = 0;
	for (int i = 1; i <= n; i++) {
		while (v1[i] > v2[j])
			j++;
		if (v1[i] == v2[j])
			ans++, j++;
	}
	cout << n - ans;
}