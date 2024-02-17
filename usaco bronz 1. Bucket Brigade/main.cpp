#include <bits/stdc++.h>
#define cin fin
#define cout fout

using namespace std;

ifstream fin ("buckets.in");
ofstream fout ("buckets.out");

char m[11][11];

int main()
{
    int i, j, ans = 0, n = 10, r1, c1, r2, c2, r3, c3;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            cin.get(m[i][j]);
            if(m[i][j] == 'B')
            {
                r1 = i;
                c1 = j;
            }
            if(m[i][j] == 'L')
            {
                r2 = i;
                c2 = j;
            }
            if(m[i][j] == 'R')
            {
                r3 = i;
                c3 = j;
            }
        }
        cin.get();
    }
    if(c1 == c2)
    {
        if(r1 == r2)
            cout << (max(r1, r2) - min(r1, r2)) + (max(c1, c2) - min(c1, c2));
        else if(c3 == c1 && r3 < max(r2, r1) && r3 > min(r2, r1))
            cout << (max(r1, r2) - min(r1, r2)) + (max(c1, c2) - min(c1, c2));
        else
            cout << (max(r1, r2) - min(r1, r2)) + (max(c1, c2) - min(c1, c2)) - 1;
    }
    else if(r1 == r2)
    {
        if(c1 == c2)
            cout << (max(r1, r2) - min(r1, r2)) + (max(c1, c2) - min(c1, c2));
        else if(r3 == r1 && c3 < max(c2, c1) && c3 > min(c2, c1))
            cout << (max(r1, r2) - min(r1, r2)) + (max(c1, c2) - min(c1, c2));
        else
            cout << (max(r1, r2) - min(r1, r2)) + (max(c1, c2) - min(c1, c2)) - 1;
    }
    else
        cout << (max(r1, r2) - min(r1, r2)) + (max(c1, c2) - min(c1, c2)) - 1;
    return 0;
}
