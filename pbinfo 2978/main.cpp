#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream in ("aur.in");
    ofstream out ("aur.out");
    long long c, n, k, i;
    in >> c >> n;
    if(c == 2 or c == 3)
        in >> k;

    char ch;
    int cnt = 0;
    char ans;
    while ( in >> ch )
    {
        if ( ch != ' ' )
            cnt ++;
        if ( cnt == k )
            ans = ch;
    }
    if (c == 2)
        out << ans;
    if(c == 1)
        out << cnt;
    if ( c == 3 )
    {
        long long p = 1;
        int n, k;
        cin >> n >> k;
        for ( int i = 1; i < k; i++ )
        {
            p *= 10;
        }
        int i = 0;
        long long maxim = 0;
        char ch;
        int cif;
        long long aux = 0;;
        while ( cin >> ch )
        {
            if ( ch != ' ' )
            {
                cif = (int) ch - 48;
                aux = aux * 10 + cif;
            }
            i ++;
            if ( i == k )
            {
                maxim = max( maxim, aux );
                aux = aux % p;
                i--;
            }
        }
        cout << maxim;
    }
    return 0;
}
