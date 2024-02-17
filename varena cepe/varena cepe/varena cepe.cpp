#include <fstream>
#include <cmath>

using namespace std;

ifstream cin("cepe.in");
ofstream cout("cepe.out");

int va[16], vb[16];

int main() {
	int a, b;
	cin >> a >> b;
	int nra = log2(a) + 1, i = nra;
	while (a) {
		va[i--] = a % 2;
		a /= 2;
	}
	i = 1;
	while (b) {
		vb[i++] = b % 2;
		b /= 2;
	}
	int nrb = i - 1;
	i = 1;
	while (va[i] == vb[i] && i <= min(nra, nrb))
		i++;
	int cb = 0, dif = i;
	for (int i = dif; i <= nrb; i++)
		cb += vb[i] * (1 << i - dif);
	int ca = 0;
	for (int i = nra; i >= dif; i--)
		ca += va[i] * (1 << nra - i);
	cout << ca + cb;
}