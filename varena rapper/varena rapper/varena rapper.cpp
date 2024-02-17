#include <fstream>
#include <string>

using namespace std;

ifstream cin("rapper.in");
ofstream cout("rapper.out");

int inv(int n) {
	int inv = 0;
	while (n) {
		inv = inv * 10 + n % 10;
		n /= 10;
	}
	return inv;
}

int main() {
	int cer;
	cin >> cer;
	if (cer == 1) {
		string s;
		int n = 0;
		while (getline(cin, s)) {
			if (s == "Final")
				break;
			n++;
		}
		cout << n - 1;
	}
	else if (cer == 2) {
		string s;
		int nrnm = 0;
		while (getline(cin, s)) {
			if (s == "Final")
				break;
			int nrn = 0;
			for (int i = 0; i < s.size(); i++)
				if (s[i] == ' ')
					nrn++;
			nrnm = max(nrn, nrnm);
		}
		cout << nrnm;
	}
	else {
		string s;
		double maxi = -1;
		while (getline(cin, s)) {
			double nota = 0;
			bool pnct = true;
			int p = 1, nr = 0, nrdp = 0, szn = 0;
			for (int i = s.size() - 1; i >= 0; i--) {
				if (s[i] == ' ')
					break;
				szn++;
				if (s[i] >= 48 && s[i] <= 57)
					nota = nota * 10 + (s[i] - '0');
				if (s[i] != '0')
					nr = 1;
				if (!pnct)
					nrdp++;
				if (s[i] == '.')
					pnct = 0;
				if (pnct && nr)
					p *= 10;
			}
			nota = inv(nota);
			if(!pnct)
				nota = (double)nota / p;
			if (nrdp == 2 || (pnct && szn == 2))
				nota = 10;
			if (maxi < nota && s.size() != 0) {
				maxi = nota;
				for (int i = 0; i < s.size() - szn; i++)
					cout << s[i];
				cout << '\n';
			}
		}
	}
}