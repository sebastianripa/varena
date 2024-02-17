#include <iostream>
#include <vector>

using namespace std;

vector <int> v;

int main() {
	int cer, n;
	cin >> cer >> n;
	if (cer == 1) {
		int nrb = 0, ogx, x = 0;
		cin >> ogx;
		for (int i = 2; i <= n; i++) {
			cin >> x;
			if (x != ogx)
				nrb++;
			if(i < n)
				ogx = x;
		}
		if (x != ogx)
			nrb++;
		cout << nrb;
	}
	else {
		int ogx, x = 0;
		cin >> ogx;
		v.push_back(ogx);
		for (int i = 2; i <= n; i++) {
			cin >> x;
			v.push_back(x);
		}
		int ec = 1, st = 0;
		for (int i = 1; i < n; i++) {
			if (v[i - 1] != v[i]) {
				if (ec > 2)
					v.erase(st, st + ec - 1);
				n -= (st + ec - 1);
				st = i;
				ec = 1;
			}
			else
				ec++;
		}
	}
}