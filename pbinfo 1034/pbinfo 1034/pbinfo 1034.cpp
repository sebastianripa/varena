#include <fstream>
#include <queue>
#define int long long

using namespace std;

ifstream cin("roata.in");
ofstream cout("roata.out");

priority_queue <pair<int, int>> pq;
int v[100005];

int32_t main() {
	int c;
	cin >> c;
	int n;
	cin >> n;
	int s = 0;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		s += v[i];
	}
	cout << s << '\n';
	for(int i = 1; i <= n; i++) {
		if (i <= c) {
			int nr = v[i] * c + (i - 1);
			pq.push({ -nr, i });
		}
		else {
			cout << pq.top().second << ' ';
			int nr = -pq.top().first;
			pq.pop();
			pq.push({ -(nr + v[i] * c), i});
		}
	}

	while (!pq.empty()) {
		cout << pq.top().second << ' ';
		if (pq.size() == 1)
			cout << '\n' <<  (-pq.top().first) % c + 1;
		pq.pop();
	}
}

/*#include <iostream>
using namespace std;
int main ()
{
	int a, b;
	cin >> a;
	cin >> b;
	cout << a * b;
	return 0;
}*/
