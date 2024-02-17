#include <bits/stdc++.h>
#define cin fin
#define cout fout

using namespace std;

ifstream fin ("kami.in");
ofstream fout ("kami.out");

int v[100005];

int main()
{
    long long m, n;
    cin >> n;
    for(long long i = 1; i <= n; i++)
        cin >> v[i];
    cin >> m;
    for(long long i = 1; i <= m; i++) {
        int cer;
        cin >> cer;
        if(!cer) {
            long long i1, val;
            cin >> i1 >> val;
            v[i1] = val;
        }
        else {
            long long sum = 0, x;
            cin >> x;
            sum += v[x];
            x--;
            while(sum > v[x] && x) {
                sum += v[x--];
                if(sum > 1000000000) {
                    x = 0;
                    break;
                }
            }
            cout << x << '\n';
        }
    }
    return 0;
}
