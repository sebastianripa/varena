#include <bits/stdc++.h>
#define cin fin
#define cout fout

using namespace std;

ifstream fin ("aeriana.in");
ofstream fout ("aeriana.out");

long long cm = 23*60+60;

int convm(int h, int m) {
    return h*60+m;
}

bool prim(long long n) {
    if(n <= 2)
        return false;
    for(int i = 2; i*i <= n; i++) {
        if(n%i == 0)
            return false;
    }
    return true;
}

bool vc(long long a1, long long a2) {
    long long sc = 0;
    if(prim(a1)) {
        while(a1) {
            sc += a1%10;
            a1 /= 10;
        }
        if(a2%sc == 0)
            return true;
        return false;
    }
    return false;
}

int main()
{
    long long cer, t, a1, a2, h1, h2, m1, m2, t1, t2, ans = 0, ansm = 0;
    cin >> cer >> t;
    if(cer == 1) {
        while(t--) {
            cin >> a1 >> a2 >> h1 >> m1 >> h2 >> m2;
            t1 = convm(h1, m1);
            t2 = convm(h2, m2);
            if(t1 > t2)
                ans = (cm - t1) + t2;
            else
                ans = t2 - t1;
            ansm = max(ans, ansm);
        }
        cout << ansm/60 << ' ' << ansm%60;
    }
    else {
        while(t--) {
            cin >> a1 >> a2 >> h1 >> m1 >> h2 >> m2;
            if(vc(a1, a2)) {
                t1 = convm(h2, m2);
                t2 = convm(h1, m1);
                if(t1 > t2)
                    ans = (cm - t1) + t2;
                else
                    ans = t2 - t1;
                ansm = max(ans, ansm);
            }
            else {
                t1 = convm(h1, m1);
                t2 = convm(h2, m2);
                if(t1 > t2)
                    ans = (cm - t1) + t2;
                else
                    ans = t2 - t1;
                ansm = max(ans, ansm);
            }
        }
        cout << ansm/60 << ' ' << ansm%60;
    }
    return 0;
}
