#include <iostream>

using namespace std;

int sp[100005];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		sp[x] = 1;
	}
}