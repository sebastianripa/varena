#include <fstream>
#include <vector>

using namespace std;

ifstream cin ("aib.in");
ofstream cout ("aib.out");

vector <int> bits(100005, 0);
int n, v[100005];

void update(int i, int val) {
	while (i <= n) {
		bits[i] += val;
		i += (i & -i);
	}
}

int presum(int i) {
	int sum = 0;
	while (i) {
		sum += bits[i];
		i -= (i & -i);
	}
	return sum;
}

int rougesum(int i, int j) {
	return presum(j) - presum(i - 1);
}

int main() {
	int m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> v[i], update(i, v[i]);
	for (int i = 1; i <= m; i++) {
		int cer;
		cin >> cer;
		if (cer == 0) {
			int a, b;
			cin >> a >> b;
			update(a, b);
		}
		else if (cer == 1) {
			int a, b;
			cin >> a >> b;
			cout << rougesum(a, b) << '\n';
		}
		else {
			int a;
			cin >> a;
			int l = 1, r = n;
			while (l <= r) {
				int mij = (l + r) / 2;
				int x = presum(mij);
				if (a == x) {
					cout << mij << '\n';
					break;
				}
				if (a < x)
					r = mij - 1;
				else l = mij + 1;
			}
			if (l > r)
				cout << -1 << '\n';
		}
	}
}
