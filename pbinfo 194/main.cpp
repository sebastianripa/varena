#include <bits/stdc++.h>
#ifndef HOME
#define cin fin
#define cout fout
#endif

using namespace std;

ifstream fin ("anagrame1.in");
ofstream fout ("anagrame1.out");

char v[100];
int n = 1;
map <char, bool> vf;
vector <char> sol;

void bkt(int cn) {
    if(cn == 0) {
        for(auto x : sol)
            cout << x;
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++) {
        sol.push_back(v[i]);
        if(!vf[v[i]]) {
            vf[v[i]] = 1;
            bkt(cn - 1);
            vf[v[i]] = 0;
        }
        sol.pop_back();
    }
}

int main()
{
    cin >> v+1;
    n = strlen(v+1);
    sort(v+1, v+n+1);
    bkt(n);
    return 0;
}
