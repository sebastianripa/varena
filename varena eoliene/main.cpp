#include <fstream>
#include <algorithm>

using namespace std;

ifstream cin ("eoliene.in");
ofstream cout ("eoliene.out");

struct femeie{
    int st,dr;
};

femeie v[1001];

int d[1001], l[1001];

bool cmp (femeie x,femeie y)
{
    if(x.dr > y.dr)
        return false;
    return true;
}

int main()
{
    int n, i, mini = 1;
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> d[i];
    for(i = 1; i <= n; i++)
        cin >> l[i];
    for(i = 1; i <= n; i++)
    {
        v[i].st = d[i]-l[i];
        v[i].dr = d[i]+l[i];
    }

    sort(v + 1, v + n + 1, cmp);
    int aux = v[1].dr;
    for(i = 2; i <= n; i++)
    {
        if(v[i].st > aux)
        {
            mini++;
            aux = v[i].dr;
        }
    }
    cout << n - mini;
    return 0;
}
