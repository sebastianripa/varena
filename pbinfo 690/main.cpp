#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//ifstream cin("domino1.in");
//ofstream cout("domino1.out");

struct pii {
	int first, second, third;
};

vector <pii> v, aux;

bool cmp(pii a, pii b) {
	if (a.first != b.first)
		return a.first < b.first;
	if (a.second != b.second)
		return a.second < b.second;
	return a.third > b.third;
}

int main() {
	int n, r, e, rt = 0;
	cin >> n >> r >> e;
	for (int i = 1; i <= n; i++) {
		cin >> v[i].first >> v[i].second;
		v[i].third = false;
		if (v[i].first < v[i].second) {
			swap(v[i].first, v[i].second);
			v[i].third = true;
			rt++;
		}
	}
	aux = v;
	sort(v.begin(), v.end(), cmp);
	for (int i = 1; i <= e; i++) {
		aux[i].first = 0;
		v.erase(find(v.begin(), v.end(), aux[i].first));
		if (aux[i].third)
			rt--;
	}
	for (int i = v.size() - 1; rt > r; i++) {
		if (v[i].third) {
			swap(v[i].first, v[i].second);
			rt--;
		}
	}
	for (pii x : v)
		cout << x.first << x.second;
}
