#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("cifru.in");
ofstream fout ("cifru.out");

long long v[10];
int main()
{
    long long a, x = 0, y = 0, ca;
    int nrc = 0, i = 0, j, n;
    fin >> a;
    ca = a;
    while(ca != 0)
    {
        nrc++;
        ca /= 10;
    }

    while(a != 0)
    {
        if(a%nrc == 0)
            x++;
        else
            v[i++] = a;
        a /= 10;
    }
    n = i;

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if((v[i] - v[j])%nrc == 0)
                y++;
        }
    }
    fout << x + y;
    return 0;
}
