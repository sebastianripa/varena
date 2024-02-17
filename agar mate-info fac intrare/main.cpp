#include <iostream>
#include <set>
#include <vector>

#define f first
#define s second

using namespace std;

set <int> st[100001];
int v[100001];

bool rez(int l, int r)
{
    int i = 0, j, ans = 0, x;
    bool ok = false;
    vector <int> ax;
    std::copy(st[0].begin(), st[r-l+1].end(), back_inserter(ax));
    for(i = 0; i <= x; i++)
    {
        if(ax[i]*2 <= ax[i+1])
            ans++;
        if(ans == 2)
            return false;
    }
    return true;
}

int main()
{
    int n, q, i, j, l, r, ogl = -1, ogr = -1;
    bool ans = false;
    cin >> n >> q;
    for(i = 0; i < n; i++)
        cin >> v[i];
    while(q--)
    {
        cin >> l >> r;
        if(ogl != -1)
        {
            if(l > ogl)
                for(i = ogl; i < l-1; i++)
                    st[i-ogl].erase(v[i]);
            else
                for(i = l; i < ogl-1; i++)
                    st[i-ogl].insert(v[i]);
        }
        if(ogr != -1)
        {
            if(r > ogr)
                for(i = ogr; i < r-1; i++)
                    st[i-ogr].erase(v[i]);
            else
                for(i = r; i < ogr-1; i++)
                    st[i-ogr].insert(v[i]);
        }
        ans = rez(l, r);
        if(ans)
            cout << "DA" << '\n';
        else
            cout << "NU" << '\n';
        ogl = l;
        ogr = r;
    }
    return 0;
}
