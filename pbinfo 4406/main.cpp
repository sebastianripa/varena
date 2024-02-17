#include <bits/stdc++.h>
#define cin fin
#define cout fout

using namespace std;

ifstream fin ("fibosnek.in");
ofstream fout ("fibosnek.out");

struct intd {
    long long f, s;
};

struct intt {
    long long f;
    intd s;
};

vector<long long> v[3005];
map<long long, bool> mp;
intt vf[30005];
vector<long long> vnf[30005];

void fibo() {
    long long a = 1, b = 1, c = 2;
    mp[1] = 1;
    mp[2] = 1;
    while(c < INT_MAX) {
        a = b;
        b = c;
        c = a + b;
        mp[c] = 1;
    }
}

long long change(long long n) {
    long long i, j;
    for(i = n+1, j = n-1; !mp[i] && !mp[j]; i++, j--)
        continue;
    if(mp[j])
        return j;
    else
        return i;
}

int main()
{
    long long cer, n, m, nrf = 0;
    bool ok2 = true;
    cin >> cer >> n >> m;
    fibo();
    for(long long i = 1; i <= n; i++) {
        long long x;
        for(long long j = 1; j <= m; j++) {
            cin >> x;
            v[j].push_back(x);
            if(i == n && j == m && !mp[x])
                ok2 = false;
        }
    }
    bool ok = false;
    long long j = 1, k = 1, l = 1;
    for(long long i = 1; i <= m; i++) {
        for(auto x : v[i]) {
            if(mp[x]) {
                nrf++;
                if(!ok) {
                    l++;
                    ok = true;
                    vf[k].f = j;
                    vf[k].s.s = x;
                }
                else
                    vf[k].s.s += x;
            }
            else {
                if(ok) {
                    ok = false;
                    vf[k++].s.f = j-1;
                }
                vnf[l].push_back(x);
            }
            j++;
        }
    }
    if(cer == 1) {
        cout << nrf;
        return 0;
    }
    if(ok) {
        ok = false;
        vf[k++].s.f = j-1;
    }
    k--;
    long long sm = 0;
    for(long long i = 1; i <= k; i++) {
        long long s = 0;
        if(i == 1) {
            s += vf[i].s.s;
            for(auto x : vnf[i])
                s += change(x);
            sm = max(s, sm);
            continue;
        }
        s += vf[i].s.s + vf[i-1].s.s;
        for(auto x : vnf[i])
            s += change(x);
        sm = max(s, sm);
    }
    if(!ok2) {
        long long s = 0;
        s += vf[k].s.s;
        for(auto x : vnf[k+1])
            s += change(x);
        sm = max(s, sm);
    }
    cout << sm;
    return 0;
}
