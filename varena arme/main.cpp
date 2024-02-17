#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin ("arme.in");
ofstream fout ("arme.out");

int v[2002];
    for(i = 1; i <= n+m; i++)
        fin >> v[i];
    sort(v+1, v+n+m+1);
    if((n+m)%2 == 1)
        for(i = m+n; i >= n; i--)
            s += v[i];
    else
        for(i = m+n; i > n; i--)
            s += v[i];
    fout << s;
    return 0;
}
