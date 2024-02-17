#include <fstream>

using namespace std;

ifstream cin("impletire.in");
ofstream cout("impletire.out");

int v1[15], v2[15];

int main() {
	int a, b, nrc = 0, ca, cb;
	cin >> a >> b;
	ca = a, cb = b;
	while (ca) {
		v1[0]++;
		ca /= 10;
	}
	while (cb) {
		v2[0]++;
		cb /= 10;
	}
	for (nrc = 1; a; nrc++, a /= 10)
		v1[v1[0] - nrc + 1] = a % 10;
	for (nrc = 1; b; nrc++, b /= 10)
		v2[v2[0] - nrc + 1] = b % 10;
	int i = 1, j = 1;
	while (i <= v1[0] && j <= v2[0]) {
		if (v1[i] > v2[j])
			cout << v1[i], i++;
		else if(v1[i] < v2[j])
			cout << v2[j], j++;
		else {
			int ci = i, cj = j;
			while (v1[ci] == v2[cj] && ci <= v1[0] && cj <= v2[0])
				ci++, cj++;
			if (v1[ci - 1] == v1[ci]) {
				while (v1[i] == v2[j] && j <= v2[0])
					cout << v2[j], j++;
			}
			else if (v2[cj - 1] == v2[cj]) {
				while (v1[i] == v2[j] && i <= v1[0])
					cout << v1[i], i++;
			}
			else {
				if (v1[ci] > v2[cj]) {
					while (v1[i] == v2[j])
						cout << v1[i], i++;
				}
				else {
					while (v1[i] == v2[j])
						cout << v2[j], j++;
				}
			}
		}
	}
	while (i <= v1[0])
		cout << v1[i], i++;
	while (j <= v2[0])
		cout << v2[j], j++;
}