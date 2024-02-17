#include <iostream>

using namespace std;

bool circular(int n, int nrc) {

}

int main() {
	int n;
	cin >> n;
	n++;
	bool ok = false;
	int cnt = 0, nrm = 0, nrc = 0;
	int cn = n;
	while (n) {
		nrc++;
		n /= 10;
	}
	while (n--) {
		if (circular(n, nrc)) {
			cnt++;
			if (!ok)
				nrm = n, ok = true;
		}
	}
}