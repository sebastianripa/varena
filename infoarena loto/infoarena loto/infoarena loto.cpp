#include <unordered_map>
#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("loto.in");
ofstream fout("loto.out");

const int Dim = 101;
int A[Dim], n, S;

int S;
vector <int> ans;

void bkt(int n, int s, int nre, int pz) {
	if (s > S)
		return;
	if (nre == 6) {
		if (s == S) {
			for (auto x : ans)
				cout << x << ' ';
			exit(0);
		}
		return;
	}
	if (pz > n)
		return;
	for (int i = 0; i <= 6; i++) {
		for (int j = 1; j <= i; j++)
			ans.push_back(A[pz]);
		bkt(n, s + A[pz] * i, nre + i, pz + 1);
		for (int j = 1; j <= i; j++)
			ans.pop_back();
	}
}


struct str {
	int a, b, c;
};

unordered_map < int, str > M;

int main() {

	fin >> n >> S;
	for (int i = 1; i <= n; ++i)
		fin >> A[i];
	if (n > 10) {
		for (int i = 1; i < n; ++i) {
			for (int j = 1; j < n; ++j) {
				for (int k = 1; k <= n; ++k) {
					int s = A[i] + A[j] + A[k];
					M[s] = { A[i],A[j],A[k] };
					if (M.find(S - s) != M.end()) {
						fout << A[i] << " " << A[j] << " " << A[k] << " " << M[S - s].a << " " << M[S - s].b << " " << M[S - s].c;
						return 0;
					}
				}
			}
		}
		fout << -1;
	}
	else {
		bkt(n, 0, 0, 0);
		fout << -1;
	}
}