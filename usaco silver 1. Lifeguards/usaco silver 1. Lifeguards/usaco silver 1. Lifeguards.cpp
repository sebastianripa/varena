#include <fstream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

ifstream cin("lifeguards.in");
ofstream cout("lifeguards.out");

const int MAX = (int)21e7;

struct lifeguard {
    int li, idx;
    bool l;
};

vector <lifeguard> v;
multiset <int> ev;
int cnt[100005];

bool cmp(lifeguard a, lifeguard b) {
    if (a.li != b.li)
        return a.li < b.li;
    if (a.l != b.l)
        return a.l < b.l;
    return a.idx < b.idx;
}

int main() {
    int n, maxi = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({ x, i, true });
        v.push_back({ y, i, false });
    }
    sort(v.begin(), v.end(), cmp);
    int last = v[0].li, mini = MAX, szmx = 0, szmn = MAX, ans = 0;
    for (lifeguard x : v) {
        if (ev.size())
            ans += x.li - last;
        if (x.l) {
            if (ev.size() == 1)
                cnt[*ev.begin()] += (x.li - last);
            ev.insert(x.idx);
            last = x.li;
        }
        else {
            if (ev.size() == 1)
                cnt[*ev.begin()] += (x.li - last);
            mini = min(mini, cnt[x.idx]);
            ev.erase(ev.find(x.idx));
            last = x.li;
        }
    }
    cout << ans - mini;
}