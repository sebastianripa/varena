#include <bits/stdc++.h>
#define cin fin
#define cout fout

using namespace std;

ifstream fin ("examen2.in");
ofstream fout ("examen2.out");

void solve1(long long l, long long c, long long e) {
    long long nre;
    cin >> nre;
    if(nre%c)
        cout << nre/c+1 << ' ' << nre%c;
    else
        cout << nre/c << ' ' << c;
}

void solve2(long long l, long long c, long long e) {
    long long l1, c1;
    cin >> l1 >> c1;
    cout << e - ((l1-1)*c + c1) + 1;
}

void solve3(long long l, long long c, long long e) {
    long long nrf = 0, nrb = 0;
    char cr;
    cin.get();
    while(e--) {
        cin.get(cr);
        if(cr == 'B')
            nrb++;
        else
            nrf++;
    }
    long long a = nrb, b = nrf, r;
    while(b) {
        r = a%b;
        a = b;
        b = r;
    }
    if(a == 1)
        cout << -1;
    else
        cout << nrb/a + nrf/a;
}

int main()
{
    long long cer, l, c, e;
    cin >> cer >> l >> c >> e;
    if(cer == 1)
        solve1(l, c, e);
    else if(cer == 2)
        solve2(l, c, e);
    else
        solve3(l, c, e);
    return 0;
}
