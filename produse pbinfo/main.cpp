#include <bits/stdc++.h>
using namespace std;

struct ura
{
    int val, cat;
};
ura v[1001];
int rast(int n)
{
    int r = 0;
    while ( n )
    {
        r *= 10;
        r += n % 10;
        n /= 10;
    }
    return r;
}
bool cmp( ura x, ura y )
{
    if ( x.cat > y.cat )
        return false;
    if ( x.cat == y.cat )
    {
        if ( x.val > y.val )
            return false;
    }
    return true;
}


sort(v + 1, v +n + 1, cmp)


int main()
{
    ifstream cin ("produse.in");
    ofstream cout ("produse.out");
    int c, n;
    cin >> c;
    cin >> n;
    int in_stock = 0, out_stock = 0;
    for ( int i = 1; i <= n; i++ )
    {
        int x;
        cin >> x;
        v[i].val = x;
        while ( x > 99 )
        {
            x /= 10;
        }
        if ( x % 2 == 0 )
            in_stock ++;
        else
            out_stock ++;
        x /= 10;

        v[i].cat = x;
    }
    sort ( v + 1, v + n + 1, cmp );

    if( c == 2)
    {
        while ( i <= n )
        {
            cout << v[i].cat << " " << v[i].val << " ";
            while ( v[i].cat == v[i+1].cat )
            {
                cout << v[++i].val<< " ";
            }
            i++;
            cout << "\n";
        }
    }
    else
        cout << in_stock << " " << out_stock;


    return 0;
}
