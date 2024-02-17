#include <iostream>

using namespace std;

int cr[100005];

void ciur(int n) {
	for (int i = 2; i <= n; i += 2)
		cr[i] = 2;
	for (int i = 3; i <= n; i += 2) {
		if (!cr[i]) {
			cr[i] = i;
			for (int j = i * i; j <= n; j += i)
				cr[j] = i;
		}
	}
}

void desc(int n) {
	while (n > 1) {
		cout << cr[n] << ' ';
		n /= cr[n];
	}
}

int main() {
	int n;
	cin >> n;
	ciur(10000);
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		cout << "Factorii primi ai nr " << x << " sunt: ";
		desc(x);
		cout << '\n';
	}
}