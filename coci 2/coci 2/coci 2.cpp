#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> v[200005];
pair <int, int> va[200005];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> va[i].first;
	for (int i = 1; i <= n; i++)
		cin >> va[i].second;
	sort(va + 1, va + n + 1);
	int nrp = 0;
	for (int i = 1; i <= n; i++) {
		if (nrp == 0) {
			nrp++;
			v[nrp].push_back(va[i].second);
			continue;
		}
		int mn = 21e8, pz = 0;
		for (int j = 1; j <= nrp; j++) {
			int aux = v[j].back() - va[i].second;
			if (mn > aux && aux > 0) {
				mn = aux;
				pz = j;
			}
		}
		if (pz) {
			v[pz].push_back(va[i].second);
			continue;
		}
		nrp++;
		v[nrp].push_back(va[i].second);
	}
	cout << nrp;
}