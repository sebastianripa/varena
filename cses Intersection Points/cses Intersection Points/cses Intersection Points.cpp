#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 100000
#define MAXNR 1000000

struct coord {
    int t;
    int c0;
    int c1;
    int c2;
};

vector<coord> v;

int bucket[2 * MAXNR];

void update(int ind, int val) {
    for (int i = ind; i < 2 * MAXNR; i += -i & i)
        bucket[i] += val;
}

int query(int ind) {
    int sum;
    sum = 0;
    for (int i = ind; i > 0; i -= -i & i)
        sum += bucket[i];
    return sum;
}

bool cmp(const coord a, const coord b) {
    return a.c0 < b.c0;
}

int main() {
    int n;
    cin >> n;
    int x1, y1, x2, y2;
    for (int i = 0; i < n; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 != x2)
            v.push_back({ 1, y1, x1 + MAXNR, x2 + MAXNR });
        else {
            v.push_back({ 2, y1, x1 + MAXNR, -1 });
            v.push_back({ 3, y2, x1 + MAXNR, -1 });
        }
    }
    sort(v.begin(), v.end(), cmp);
    long long sol = 0;
    for (coord cv : v) {
        if (cv.t == 1) sol += query(cv.c2) - query(cv.c1 - 1);
        else if (cv.t == 2) update(cv.c1, 1);
        else if (cv.t == 3) update(cv.c1, -1);
    }
    cout << sol;
}