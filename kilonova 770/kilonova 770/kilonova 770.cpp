#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream cin("concurs.in");
ofstream cout("concurs.out");

int vf[55];
vector <int> v[55];
vector <pair<int, int>> vm;

int main() {
	int n;
	cin >> n;
	int nj = 0;
	for(int i = 1; i <= n; i++) {
		int j, e;
		cin >> j >> e;
		vf[j]++;
		v[j].push_back(e);
		nj++;
	}
	cout << nj << '\n';
	for (int i = 1; i <= 50; i++) {
		if (vf[i]) {
			sort(v[i].begin(), v[i].end());
			vm.push_back({ vf[i], i });
			cout << vf[i] << ' ';
		}
	}
	cout << '\n';
	sort(vm.begin(), vm.end());
	int ind = vm.size() - 1;
	int idx1 = vm[ind--].second, idx2 = vm[ind--].second, i = 0, j;
	while (true) {
		for (j = 0; i < v[idx1].size(), j < v[idx2].size(); i++, j++)
			cout << idx1 << ' ' << v[idx1][i] << '\n' << idx2 << ' ' << v[idx2][j] << '\n';
		if (ind < 0) {
			while (i < v[idx1].size())
				cout << idx1 << ' ' << v[idx1][i++] << '\n';
			while (j < v[idx2].size())
				cout << idx2 << ' ' << v[idx2][j++] << '\n';
			break;
		}
		if (j == v[idx2].size())
			j = 0, idx2 = vm[ind--].second;
		if(i == v[idx1].size())
			i = j, idx1 = idx2, j = 0, idx2 = vm[ind--].second;
	}
}