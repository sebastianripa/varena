#include <iostream>
#define int unsigned long long

using namespace std;

//ifstream cin("anaf.in");
//ofstream cout("anaf.out");

int a[10005], b[15];

void AtribMic(int x[], int n) {
	x[0] = 0;
	if (n == 0) {
		x[0] = 1;
		x[x[0]] = 0;
	}
	else {
		for (; n != 0; n /= 10) {
			x[0]++;
			x[x[0]] = n % 10;
		}
	}
}

void Adunare(int x[], int y[]) {
	int t = 0;
	if (x[0] < y[0])
		x[0] = y[0];
	for (int i = 1; i <= x[0]; i++, t /= 10)
	{
		t = x[i] + y[i] + t;
		x[i] = t % 10;
	}
	if (t != 0) {
		x[0]++;
		x[x[0]] = t;
	}
}

void Scadere(int x[], int y[]) {
	int j, t = 0;
	for (int i = 1; i <= x[0]; i++) {
		if (x[i] >= y[i])
			x[i] -= y[i];
		else {
			j = i + 1;
			while (x[j] == 0)
				x[j++] = 9;
			x[j]--;
			x[i] = 10 + x[i] - y[i];
		}
	}
	while (x[0] > 1 && x[x[0]] == 0)
		x[0]--;
}

void ProdusMic(int x[], int n) {
	int t = 0;
	for (int i = 1; i <= x[0]; i++, t /= 10) {
		t += x[i] * n;
		x[i] = t % 10;
	}
	for (; t != 0; t /= 10) {
		x[0]++;
		x[x[0]] = t % 10;
	}
}

int Divide(int x[], int n) {
	int r = 0;
	for (int i = x[0]; i > 0; i--) {
		r = 10 * r + x[i];
		x[i] = r / n;
		r %= n;
	}
	while (x[x[0]] == 0 && x[0] > 1)
		x[0]--;
	return r;
}

int32_t main() {
	int n;
	cin >> n;
	AtribMic(a, n);
	int op;
	cin >> op;
	for (int i = 1; i <= op; i++) {
		char c;
		cin >> c;
		int k;
		cin >> k;
		AtribMic(b, k);
		if (c == '+')
			Adunare(a, b);
		if (c == '-')
			Scadere(a, b);
		if (c == '/')
			Divide(a, k);
		if (c == '%')
			AtribMic(a, Divide(a, k));
		if (c == '*')
			ProdusMic(a, k);
	}
	for (int i = 1; i <= sizeof(a) / sizeof(a[i]); i++)
		cout << a[i];
}