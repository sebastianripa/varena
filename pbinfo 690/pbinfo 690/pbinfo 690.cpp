#include <iostream>

using namespace std;

//ifstream cin("domino1.in");
//ofstream cout("domino1.out");

pair <int, int> v[10005];

int main() {
    int n, r, e;
    cin >> n >> r >> e;
    for (int i = 1; i <= n; i++)
        cin >> v[i].first >> v[i].second;
    for (int i = 1; i <= n; i++) {
        if (n - i + 1 == e) {
            e--;
            continue;
        }
        if (r > 0) {
            bool ok1 = false, ok2 = false;
            if (v[i].first < v[i].second) {
                swap(v[i].first, v[i].second);
                ok1 = true;
            }
            if (v[i + 1].first < v[i + 1].second) {
                swap(v[i + 1].first, v[i + 1].second);
                ok2 = true;
            }
            if ((v[i].first < v[i + 1].first || (v[i].first == v[i + 1].first && v[i].second < v[i + 1].second)) && e > 0) {
                e--;
                if (ok1)
                    swap(v[i].first, v[i].second);
                if (ok2)
                    swap(v[i + 1].first, v[i + 1].second);
                continue;
            }
            else if (e > 0 && (v[i].first == v[i + 1].first && v[i].second == v[i + 1].second)) {
                if (ok1) {
                    e--;
                    if (ok2)
                        swap(v[i + 1].first, v[i + 1].second);
                    continue;
                }
            }
            if (ok1)
                swap(v[i].first, v[i].second);
            if (ok2)
                swap(v[i + 1].first, v[i + 1].second);
        }
        else {
            if ((v[i].first < v[i + 1].first || (v[i].first == v[i + 1].first && v[i].second < v[i + 1].second)) && e > 0) {
                e--;
                continue;
            }
        }
        if (v[i].first < v[i].second && r > 0) {
            swap(v[i].first, v[i].second);
            r--;
        }
        cout << v[i].first << v[i].second;
    }
}