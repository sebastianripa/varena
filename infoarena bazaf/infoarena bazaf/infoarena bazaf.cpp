#include <fstream>
#include <vector>
#define int long long

using namespace std;

ifstream cin("bazaf.in");
ofstream cout("bazaf.out");

vector <int> ans;
int v[100005];

signed main() {
	int cer;
	cin >> cer;
	if (cer == 1) {
		int n;
		cin >> n;
		int fact = 1, x = 1;
		while (fact < n) {
			x++;
			fact *= x;
		}
		fact /= x;
		x--;
		cout << x << ' ';
		while (x) {
			ans.push_back(n / fact);
			n %= fact;
			fact /= x;
			x--;
		}
		for (int i = ans.size() - 1; i >= 0; i--)
			cout << ans[i] << ' ';
	}
	else {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> v[i];
		int xm = 0;
		for (int i = 1; i <= n; i++) {
			int j = i;
			while (v[j] > j) {
				int a = v[j] / (j + 1);
				v[j + 1] += a;
				v[j] %= (j + 1);
				xm = j+1;
				j++;
			}
		}
		cout << xm << ' ';
		for (int i = 1; i <= xm; i++)
			cout << v[i] << ' ';
	}
}