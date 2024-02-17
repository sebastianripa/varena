#include <fstream>
#include <vector>

using namespace std;

ifstream cin("sstabil.in");
ofstream cout("sstabil.out");

vector <int> v;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	for (int i = 1; i < v.size(); i++) {
		if (v[i] + v[i - 1] < 10) {
			v[i - 1] += v[i];
			v.erase(v.begin() + i);
			i--;
		}
	}
	for (auto x : v)
		cout << x;
}