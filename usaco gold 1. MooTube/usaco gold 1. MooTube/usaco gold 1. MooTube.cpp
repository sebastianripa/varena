#include <iostream>

using namespace std;

int minrel[100005];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		int n1, n2, r;
		cin >> n1 >> n2 >> r;
		minrel[n1] = min(minrel[n1], r);
		minrel[n2] = min(minrel[n2], r);
	}
	return 0;
}