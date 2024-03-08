#include <fstream>
#include <vector>

using namespace std;

ifstream cin("momente.in");
ofstream cout("momente.out");

const int MX = 235959;
vector <int> bit(MX + 5, 0);
int z[3][4];

//verificare

bool bun(int n) {
	if (n < 1000) {
		if (n % 100 < 60)
			return 1;
		else return 0;
	}
	if (n < 100000) {
		if (n % 100 >= 60)
			return 0;
		if (n / 100 % 100 < 60)
			return 1;
		else return 0;
	}
	if (n % 100 >= 60)
		return 0;
	if (n / 100 % 100 >= 60)
		return 0;
	if (n / 10000 < 24)
		return 1;
	else return 0;
}

int ogl(int n) {
	int inv = 0;
	while (n) {
		inv = inv * 10 + n % 10;
		n /= 10;
	}
	return inv;
}

bool palindrom(int n) {
	return n == ogl(n);
}

//aib

void update(int i, int val) {
	while (i <= MX) {
		bit[i] += val;
		i += (i & -i);
	}
}

int sum(int i) {
	int sum = 0;
	while (i > 0) {
		sum += bit[i];
		i -= (i & -i);
	}
	return sum;
}

//zile luna

int nrz(int n) {
	if (n == 2)
		return 28;
	if (n % 2) {
		if (n <= 7)
			return 31;
		else return 30;
	}
	else {
		if (n <= 7)
			return 30;
		else return 31;
	}
}

int main() {
	//precalc
	int nrp = 0;
	for (int i = 0; i <= MX; i++) {
		if (bun(i) && palindrom(i))
			nrp++, update(i + 1, 1);
	}
	int t;
	cin >> t;
	cin.get();
	while (t--) {
		char c;
		int nrs = 0, idx = 1, i = 1, ord = 0, ok = 0;
		z[1][1] = z[1][2] = z[1][3] = z[2][1] = z[2][2] = z[2][3] = 0;
		while (cin.get(c)) {
			if (c == '\n')
				break;
			if (c == ' ') {
				if (i < 3)
					i++;
				if (i == 3)
					ord++;
				if (ord > 2 && ok == 1) {
					int x = z[idx][3] % 10;
					z[idx][3] /= 10;
					z[idx][3] *= 100;
					z[idx][3] += x;
				}
				nrs++;
				if (nrs == 5)
					idx++, i = 1, ord = 0;
				ok = 0;
				continue;
			}
			ok++;
			z[idx][i] = z[idx][i] * 10 + (c - 48);
		}
		int ans = 0;
		if (z[1][1] == z[2][1] && z[1][2] == z[2][2]) {
			cout << sum(z[2][3] + 1) - sum(z[1][3]) << '\n';
			continue;
		}
		ans += nrp - sum(z[1][3]);
		ans += sum(z[2][3] + 1);
		if (z[1][1] == z[2][1]) {
			cout << ans + (z[2][2] - z[1][2] - 1) * nrp << '\n';
			continue;
		}
		for (int i = z[1][1] + 1; i < z[2][1]; i++)
			ans += (nrz(i) * nrp);
		ans += ((nrz(z[1][1]) - z[1][2]) * nrp);
		ans += ((z[2][2] - 1) * nrp);
		cout << ans << '\n';
	}
}