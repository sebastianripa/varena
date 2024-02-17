#include <fstream>
#define double float

using namespace std;

ifstream cin("permeuler.in");
ofstream cout("permeuler.out");

int phi(int n) {
	int ans = n, d = 2;
	while (n != 1) {
		if (n % d == 0) {
			ans = ans / d * (d - 1);
			while (n % d == 0)
				n /= d;
		}
		d++;
		if (d * d > n)
			d = n;
	}
	return ans;
}

bool isPerm(int n, int m) {
	int vf1[10], vf2[10];
	for (int i = 0; i <= 9; i++)
		vf1[i] = vf2[i] = 0;
	while (n)
		vf1[n % 10]++, n /= 10;
	while (m)
		vf2[m % 10]++, m /= 10;
	for (int i = 0; i <= 9; i++) {
		if (vf1[i] != vf2[i])
			return 0;
	}
	return 1;
}


int main() {
	int x, pz = 1;
	double mini = 21e8;
	while (cin >> x) {
		int nr = phi(x);
		double ans = (double)x / (double)nr;
		if (isPerm(nr, x) && mini > ans)
			mini = ans, pz = x;
	}
	cout << pz;
}