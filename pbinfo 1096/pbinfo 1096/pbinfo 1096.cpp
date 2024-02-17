#include <iostream>

using namespace std;

int v[1005];

int main() {
	int n, idx, maxx = 0;
	cin >> n >> v[1];
	for (int i = 2; i <= n; i++) {
		cin >> v[i];
		if (maxx < v[i - 1] * v[i]) {
			maxx = v[i - 1] * v[i];
			idx = i;
		}
	}
	v[idx - 1] = v[idx - 1] * v[idx];
	for (int i = idx; i <= n; i++)
		v[i] = v[i + 1];
	n--;
	maxx = 0;
	for (int i = 2; i <= n; i++) {
		if (maxx < v[i - 1] * v[i]) {
			maxx = v[i - 1] * v[i];
			idx = i;
		}
	}
	v[idx - 1] = v[idx - 1] * v[idx];
	long long s = 0;
	for (int i = 1; i <= n; i++) {
		if(i != idx)
			s += v[i];
	}
	cout << s;
}