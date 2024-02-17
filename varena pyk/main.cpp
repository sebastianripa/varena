#include <fstream>

using namespace std;
ifstream in ( "pyk.in" );
ofstream out ( "pyk.out" );
int v[ 10005 ], cnt[ 10005 ], rasp[ 10005 ], prim[ 10005 ];
int main()
{
    v[ 0 ] = 1;
    v[ 1 ] = 1;
    for ( int i = 2; i < 10005; i ++ )
    {
        if ( v[ i ] == 0 )
        {
            for ( int j = i + i; j < 10005; j += i )
                v[ j ] = 1;
        }
    }
    int poz = 0;
    for ( int i = 2; i < 10005; i ++ )
    {
        if ( v[ i ] == 0 )
            prim[ poz ++ ] = i;
    }
    int cer, k, n;
    in >> cer;
    in >> k >> n;
    int a, ca, ok = 0, maxx = 0, minn = 10000000, cif;
    for ( int i = 0; i < n; i ++ )
    {
        in >> a;
        ca = a;
        ok = 0;
        cif = ca % 10;
        while ( ca > 0 )
        {
            if ( ca % 10 != cif )
            {
                ok = 1;
                break;
            }
            ca = ca / 10;
        }
        if ( ok == 0 )
        {
            if ( a > maxx )
                maxx = a;
            if ( a < minn )
                minn = a;
        }
        ca = a;
        int fac = 0;
        while ( ca > 1 )
        {
            while ( ca % prim[ fac ] == 0 )
            {
                ca /= prim[ fac ];
                cnt[ prim[ fac ] ] ++;
            }
            fac ++;
        }
    }
    if ( cer == 1 && maxx > 0 )
        out << minn << " " << maxx;
    else if ( cer == 1 && maxx == 0 )
        out << 1;
    if ( cer == 2 )
    {
        int cont = 0;
        for ( int i = 0; i < 10005; i ++ )
        {
            if ( cnt[ i ] > 0 )
            {
                int z = cnt[ i ];
                while ( 1 )
                {
                    if ( z % k != 0 )
                    {
                        z ++;
                        rasp[ i ] ++;
                    }
                    else
                        break;
                }
            }
        }
        for ( int i = 0; i < 10005; i ++)
        {
            if ( rasp[ i ] > 0 )
                cont ++;
        }
        if ( cont == 0 )
        {
            out << 1;
            out << '\n';
            out << 2 << " " << k;
        }
        else
        {
            out << cont;
            out << '\n';
            for ( int i = 0; i < 10005; i ++ )
            {
                if ( rasp[ i ] > 0 )
                {
                    out << i << " " << rasp[ i ];
                    out << '\n';
                }
            }
        }
    }
    return 0;
}
