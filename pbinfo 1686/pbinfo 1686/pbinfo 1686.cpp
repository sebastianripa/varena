#include <fstream>
#include <vector>

using namespace std;

ifstream cin("leduri.in");
ofstream cout("leduri.out");

vector <bool> v1, v2, temp;
int n;

void schimbPos(bool& a) {
	if (a)
		a = 0;
	else
		a = 1;
}

void update(int poz, vector <bool>& v) {
	v[poz] = !v[poz];
	if (poz > 0)
		v[poz - 1] = !v[poz - 1];
	if (poz < n)
		v[poz + 1] = !v[poz + 1];
}

bool isEqual(vector <bool>& v) {
	for (int i = 1; i <= n; i++) {
		if (v[i] != v2[i])
			return false;
	}
	return true;
}

int main() {
	cin >> n;
	v1.resize(n + 1);
	v2.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		v1[i] = x;
	}
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		v2[i] = x;
	}
	temp = v1;
	int cnt1 = 0, cnt2 = 0;
	for (int i = 2; i <= n; i++) {
		if (temp[i - 1] != v2[i - 1]) {
			cnt1++;
			update(i, temp);
		}
	}
	if (!isEqual(temp))
		cnt1 = 1e9;
	temp = v1;
	cnt2 = 1;
	update(1, temp);
	for (int i = 2; i <= n; i++) {
		if (temp[i - 1] != v2[i - 1]) {
			cnt2++;
			update(i, temp);
		}
	}
	if (!isEqual(temp))
		cnt2 = 1e9;
	cout << min(cnt1, cnt2);
}