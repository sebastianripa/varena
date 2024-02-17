#include <fstream>

using namespace std;

ifstream cin("dominew.in");
ofstream cout("dominew.out");

#define MAXN 1000000
#define MAXM 8000

int v1[MAXN + 1];
int v2[MAXM + 1];

int main()
{
    int n;
    cin >> n;
    int i;
    for (i = 1; i <= n; i++)
        cin >> v1[i];
    int m;
    cin >> m;
    int st, dr, mij, poz, j;
    for (i = 1; i <= m; i++)
    {
        cin >> v2[i];
        st = 1;
        dr = n;
        poz = 0;
        while (st <= dr) {
            mij = (st + dr) / 2;
            if (v1[mij] < v2[i]) {
                poz = mij;
                st = mij + 1;
            }
            else
                dr = mij - 1;
        }
        for (j = 1; j < i; j++) {
            if (v2[j] < v2[i])
                poz++;
        }
        cout << poz + 1 << ' ';
    }
}