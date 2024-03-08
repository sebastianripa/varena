#include <fstream>

using namespace std;

ifstream cin("progresie.in");
ofstream cout("progresie.out");

int put[1005], p2[1005];

int main() {
	int n, k = 1, pk = 0;
	cin >> n;
	p2[pk] = 2;
	put[pk] = 0;
	for (int i = 1; i <= n; i++) {
		if (i - 1 == p2[pk]) {
			k *= 2;
			pk++;
			put[pk] = k / 2;
			p2[pk] = p2[pk - 1] * 2;
			k--;
		}
		else {
			for (int j = pk; j >= 0; j--) {
				if ((i - 1) % p2[j] == 0) {
					k += put[j + 1];
					k--;
					break;
				}
			}
		}
		k++;
		cout << k << ' ';
	}
}