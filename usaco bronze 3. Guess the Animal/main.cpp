#include <bits/stdc++.h>
#define cin fin
#define cout fout

using namespace std;

ifstream fin("guess.in");
ofstream fout("guess.out");

string charac[101][101];
string anim[101];
int nroc[101];

int main()
{
    int i, j, k, l, ans = 0, ansm = 0, n;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> anim[i] >> nroc[i];
        for(j = 1; j <= nroc[i]; j++)
            cin >> charac[i][j];
    }
    for(i = 1; i <= n; i++)
    {
        for(j = i+1; j <= n; j++)
        {
            for(k = 1; k <= nroc[i]; k++)
            {
                for(l = 1; l <= nroc[j]; l++)
                {
                    if(charac[i][k] == charac[j][l])
                        ans++;
                }
            }
            ansm = max(ans, ansm);
            ans = 0;
        }

    }
    cout << ansm+1;
    return 0;
}
