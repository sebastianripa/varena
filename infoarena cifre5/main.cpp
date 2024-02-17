#include <bits/stdc++.h>

using namespace std;

ifstream fin ("cifre5.in");
ofstream fout ("cifre5.out");

int v1[10] = {0, 2, 5, 5, 3, 5, 6, 3, 7, 6};
int v2[10] = {0, 4, 1, 2, 4, 3, 1, 3, 0, 1};

int main()
{
    unsigned long long cer, cf, nrb = 0, pr = 1;
    char c;
    fin >> cer;
    fin.get();
    if(cer == 1)
    {
        while(fin.get(c))
        {
            cf = c;
            cf -= 48;
            nrb += v1[cf];
        }
        fout << nrb;
    }
    else
    {
        while(fin.get(c))
        {
            cf = c;
            cf -= 48;
            pr *= (v2[cf] + 1);
        }
        fout << pr - 1;
    }
    return 0;
}
