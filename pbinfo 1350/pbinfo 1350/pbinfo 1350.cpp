#include <fstream>

using namespace std;

ifstream cin("produs2.in");
ofstream cout("produs2.out");

int v[1000005];

int main() {
    int n, p;
    cin >> n >> p;
    v[0] = 1;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    int l = 1, r = 1;
    long long pr = 1, ans = 0;
    bool ok = true;
    while (l <= n) {
        if (pr > p || r - 1 == n) {
            if(r - 1 == n && pr <= p && ok)
                ans += (r - l), ok = false;
            pr /= v[l];
            l++;
            continue;
        }
        ans += (r - l);
        pr *= v[r];
        r++;
    }
    cout << ans;
}