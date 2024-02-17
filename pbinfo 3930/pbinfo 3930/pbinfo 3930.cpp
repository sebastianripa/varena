#include <fstream>

using namespace std;

ifstream cin("perioada1.in");
ofstream cout("perioada1.out");

int main() {
	long long n, r = 10, nrz = 0;
	cin >> n;
	do {
		r %= n;
		r *= 10;
		nrz++;
	} while (r != 10);
	cout << nrz;
}