#include <iostream>
#include <vector>

using namespace std;

vector <pair<int, int>> sm, smen;
int v[1000005];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		int x = v[i] - v[i - 1];
		smen.push_back({ x, i - 1 });
	}
	for (int i = 0; i < n; i++) {
		sm = smen;
		int j = i;
		while (sm.size() > 1) {
			if (j > 0 && j < sm.size() - 1) {
				if (sm[j] <= sm[j + 1]) {
					sm[j + 1].first += sm[j].first;
					sm.erase(j + sm.begin());
					j--;
				}
				else {
					sm[j + 1].first += sm[j].first;
					sm.erase(j + sm.begin());
				}
			}
			else if (j == 0) {
				sm[j + 1].first += sm[j].first;
				sm.erase(j + sm.begin());
			}
			else {
				sm[j + 1].first += sm[j].first;
				sm.erase(j + sm.begin());
				j--;
			}
		}
		cout << sm[0].second << ' ';
	}
	//cout << 100;
	return 0;
}
