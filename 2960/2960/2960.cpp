#include <iostream>
#include <algorithm>

using namespace std;

int v[5005];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v, v + n);

}