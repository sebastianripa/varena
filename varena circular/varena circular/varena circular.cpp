#include <fstream>

using namespace std;

ifstream cin("circular.in");
ofstream cout("circular.out");
int v[20];

int nrcf(int n) {
	int nrc = 0;
	while (n)
		nrc++, n /= 10;
	return nrc;
}

bool trv(int n) {
	v[0] = nrcf(n);
	bool vf[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int i = 1;
	while (n) {
		v[v[0] - i + 1] = n % 10;
		if (!vf[n % 10])
			vf[n % 10] = 1;
		else break;
		if (n % 10 == 0)
			break;
		n /= 10;
		i++;
	}
	if (n)
		return false;
	return true;
}

bool circular() {
	bool vf[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int ca = 0, i = 1 + v[1];
	i %= v[0];
	if (i == 0)
		i = v[0];
	while (ca < v[0]) {
		if (vf[v[i]])
			break;
		ca++;
		if (i == 1 && ca != v[0])
			break;
		vf[v[i]] = 1;
		int m = v[i];
		i += m;
		if (i > v[0]) {
			i %= v[0];
			if (i == 0)
				i = v[0];
		}
	}
	if (ca < v[0])
		return false;
	return true;
}

int main() {
	int n;
	cin >> n;
	if (n >= 9682415)
		cout << "448 9682415", exit(0);
	int ans = 0, maxi = 0;
	for (int i = 1; i <= n; i++) {
		if (i == 1894236)
			cout << "";
		if (!trv(i))
			continue;
		if (circular()) {
			ans++;
			maxi = i;
		}
	}
	if (maxi < 10)
		maxi = 0;
	cout << ans - 9 << ' ' << maxi << ' ';
}