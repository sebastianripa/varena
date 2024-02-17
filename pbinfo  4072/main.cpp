#include <iostream>
#define f first
#define s second

using namespace std;

//ifstream cin ("graf_partial.in");
//ofstream cout ("graf_partial.out");

int vf[1005];
bool m[105][105];
pair <int, int> v[1005];

int main()
{
    int n, n1, n2, nrm = 0;
    cin >> n;
    while(cin >> n1 >> n2) {
        vf[n1]++;
        vf[n2]++;
        v[nrm].f = n1;
        v[nrm++].s = n2;
        m[n1][n2] = 1;
        m[n2][n1] = 1;
    }
    int ans = nrm;
    for(int i = 1; i <= nrm-1; i++) {
        if(vf[v[i].f]%2 ==  vf[v[i].s]%2) {
            ans--;
            vf[v[i].f]--;
            vf[v[i].s]--;
        }
    }
    cout << ans;
    return 0;
}
