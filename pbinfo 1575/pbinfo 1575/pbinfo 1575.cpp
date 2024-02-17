#include <fstream>
#include <string>
#include <vector>

using namespace std;

ifstream cin("paritate.in");
ofstream cout("paritate.out");

int nrb2(int n) {
	int nr = 1, p = 1, cn = n;
	while (cn) {
		p *= 10;
		cn /= 10;
	}
	p /= 100;
	while (p) {
		nr *= 2;
		if (n / p % 10)
			nr++;
		p /= 10;
	}
	return nr;
}

vector <int> v;

int main() {
	string s;
	cin >> s;
	int nr1 = 0;
	bool ok = true;
	for (int i = 0; i < s.size(); i++) {
		string aux = s.substr(i, 1);
		if (i % 8 == 0) {
			if (nr1 % 2) {
				ok = false;
				v.push_back(i / 8 - 1);
			}
			nr1 = 0;
		}
		if (aux == "1")
			nr1++;
	}
	if (nr1 % 2) {
		ok = false;
		v.push_back(s.size() / 8 - 1);
	}
	if (ok) {
		cout << "DA" << '\n';
		for (int i = 0; i < s.size(); i += 8) {
			string temp = s.substr(i + 1, 7);
			string aux = "0";
			aux += temp;
			int x = stoi(aux);
			x = nrb2(x);
			char c = x;
			cout << c;
		}
	}
	else {
		cout << "NU" << '\n';
		for (auto x : v)
			cout << x << ' ';
	}
}