#include <iostream>

using namespace std;

struct point {
	int x, y;
};

struct triangle {
	point a, b, c;
};

triangle v[70];

int main() {
	int n;
	cin >> n;
	int ba = 0, pz = 0;
	for (int i = 1; i <= n; i++) {
		cin >> v[i].a.x;
		cin >> v[i].a.y;
		cin >> v[i].b.x;
		cin >> v[i].b.y;
		cin >> v[i].c.x;
		cin >> v[i].c.y;
	}

}