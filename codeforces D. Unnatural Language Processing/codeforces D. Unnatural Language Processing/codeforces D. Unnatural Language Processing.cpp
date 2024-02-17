#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		for (int i = 0; i < n; i++) {
			if (s[i] != 'a' && s[i] != 'e') {
				if (i + 3 >= n) {
					if(i + 2 >= n)
						cout << s[i] << s[i + 1], i++;
					else
						cout << s[i] << s[i + 1] << s[i + 2], i += 2;
				}
				else {
					if(s[i + 3] != 'a' && s[i + 3] != 'e')
						cout << s[i] << s[i + 1] << s[i + 2] << '.', i += 2;
					else
						cout << s[i] << s[i + 1] << '.', i++;
				}
			}
		}
		cout << '\n';
	}
}