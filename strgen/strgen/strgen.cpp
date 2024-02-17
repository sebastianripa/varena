#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

ifstream cin("strgen.in");
ofstream cout("strgen.out");

vector <string> v;

int main() {
	v.push_back("$");
	char c;
	int pz = 0;
	string s1, s2, s;
	s += '$';
	while (cin >> c) {
		if (c != '>') {
			s2 += c;
			s2 += s1;
			s1 = s2;
			s2 = "";
		}
		else {
			if (s1 != "")
				s.insert(pz, s1), s1 = "";
			pz++;
			if (pz == s.size())
				pz = 0;
		}
	}
	if (s1 != "")
		s.insert(pz, s1), s1 = "";
	cout << s;
	/*string s, s1;
	char c;
	int pz = 0;
	s += '$';
	while (cin >> c) {
		if (c != '>')
			s1.push_back(c);
		else {
			if (!s1.empty()) {
				reverse(s1.begin(), s1.end());
				s.insert(pz, s1);
				s1.clear();
			}
			pz++;
			if(pz == s.size())
				pz = 0;
		}
	}
	if (!s1.empty()) {
		reverse(s1.begin(), s1.end());
		s.insert(pz, s1);
		s1.clear();
	}
	for (int i = 0; i < s.size(); i++)
		cout << s[i];*/
}