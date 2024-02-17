#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int v[3];
		bool ok = false;
		cin >> v[0] >> v[1] >> v[2];
		sort(v, v + 3);
		if (v[0] == v[1] && v[1] == v[2]) 
			ok = 1;
		if (v[0] == v[2] - v[0] && v[0] == v[1]) 
			ok = 1;
		if (v[0] == v[1] - v[0] && v[0] == v[2] - v[0]) 
			ok = 1;
		if (v[0] == v[1] - v[0] && v[0] == v[2] - v[0] - v[0]) 
			ok = 1;
		if (v[0] == v[1] && v[0] == v[2] - v[0] - v[0]) 
			ok = 1;
		if (v[0] == v[1] && v[0] == v[2] - v[0] - v[0] - v[0]) 
			ok = 1;
		if (ok)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}