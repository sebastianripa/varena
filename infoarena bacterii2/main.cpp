#include <fstream>

using namespace std;

ifstream cin ("bacterii2.in");
ofstream cout ("bacterii2.out");

long long v[300005], vf[600005];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        long long maxi = 0;
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> v[i];
        cin >> m;
        for(int i = 1; i <= m; i++) {
            int x;
            cin >> x;
            maxi = max(maxi, x+v[i]);
            for(int j = 1; j <= n; j++)
                vf[x+v[j]]++;
        }
        for(int i = 1; i <= maxi; i++) {
            if(vf[i])
                cout << i << ' ' << vf[i] << '\n';
            vf[i] = 0;
        }
        cout << '\n';
    }
    return 0;
}
