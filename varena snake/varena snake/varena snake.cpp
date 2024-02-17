#include <fstream>
#include <queue>

using namespace std;

ifstream cin("snake.in");
ofstream cout("snake.out");

int m[1005][1005], mt[1005][1005];
queue <pair<int, int>> q;

int main() {
	int cer;
	cin >> cer;
	int n, mut;
	cin >> n >> mut;
	int zid;
	cin >> zid;
	for (int i = 1; i <= zid; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		m[n1][n2] = 1;
	}
	int mere;
	cin >> mere;
	for (int i = 1; i <= mere; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		m[n1][n2] = 2;
	}
	int i = 1, j = 1, parte = 1, l = 1;
	while (mut--) {
		if (mt[i][j]) {
			cout << q.back().first << ' ' << q.back().second << ' ' << q.size() << ' ' << q.front().first << ' ' << q.front().second;
			exit(0);
		}
		if (m[i][j] == 2) {
			l++;
			m[i][j] = 0;
		}
		else if (!q.empty()) {
			int it = q.front().first, jt = q.front().second;
			mt[it][jt] = 0;
			q.pop();
		}
		q.push({ i, j });
		mt[i][j] = 1;
		if (parte == 1) {
			j++;
			if (j > n)
				j = 1;
			if (m[i][j] == 1) {
				parte = 2;
				j--;
				if (j < 1)
					j = n;
			}
		}
		if (parte == 2) {
			i++;
			if (i > n)
				i = 1;
			if (m[i][j] == 1) {
				parte = 3;
				i--;
				if (i < 1)
					i = n;
			}
		}
		if (parte == 3) {
			j--;
			if (j < 1)
				j = n;
			if (m[i][j] == 1) {
				parte = 4;
				j++;
				if (j > n)
					j = 1;
			}
		}
		if (parte == 4) {
			i--;
			if (i < 1)
				i = n;
			if (m[i][j] == 1) {
				parte = 1;
				i++;
				if (i > n)
					i = 1;
				j++;
				if (j > n)
					j = 1;
			}
		}
	}
	if (mt[i][j]) {
		cout << q.back().first << ' ' << q.back().second << ' ' << q.size() << ' ' << q.front().first << ' ' << q.front().second;
		exit(0);
	}
	if (m[i][j] == 2) {
		l++;
		m[i][j] = 0;
	}
	else if (!q.empty()) {
		int it = q.front().first, jt = q.front().second;
		mt[it][jt] = 0;
		q.pop();
	}
	q.push({ i, j });
	mt[i][j] = 1;
	cout << i << ' ' << j << ' ';
	if (cer == 2 || cer == 3)
		cout << l << ' ';
	if (cer == 3)
		cout << q.front().first << ' ' << q.front().second;
}