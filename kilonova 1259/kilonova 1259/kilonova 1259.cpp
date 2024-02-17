#include <fstream>

using namespace std;

ifstream cin("secv.in");
ofstream cout("secv.out");

#define MAXN 30000

int v[MAXN + 1];
int st[MAXN + 1], dr[MAXN + 1];

int main()
{
    int n;
    cin >> n;
    int i, maxx;
    maxx = 0;
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
        maxx = max(maxx, v[i]);
    }
    st[0] = v[0];
    for (i = 1; i < n; i++)
        st[i] = max(st[i - 1], v[i]);
    dr[n - 1] = v[n - 1];
    for (i = n - 2; i >= 0; i--)
        dr[i] = max(dr[i + 1], v[i]);
    int ind1, ind2;
    maxx += st[1] + dr[n - 1];
    ind1 = 1;
    ind2 = n - 1;
    for (i = 1; i < n - 1; i++)
    {
        if (st[i - 1] + dr[i + 1] + v[i] < maxx)
        {
            maxx = st[i - 1] + dr[i + 1] + v[i];
            ind1 = i;
            ind2 = i + 1;
        }
    }
    cout << maxx << '\n' << ind1 << " " << ind2;
}