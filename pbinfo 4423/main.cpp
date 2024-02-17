#include <iostream>
#include <fstream>
#define NMAX 1000001

using namespace std;
ifstream in ("secv2.in");
ofstream out ("secv2.out");
bool ciur[1000001];
int u[200001];

void ciuruire()
{
    ciur[1] = 1;
    ciur[0] = 1;

    for (int i = 4; i < NMAX; i += 2)
        ciur[i] = 1;

    for (int i = 3; i * i < NMAX; i += 2)
        for (int j = i * i; j < NMAX; j += i)
            ciur[j] = 1;
}



int main()
{
    int n, k,ct=0,lmax = 0, x,poz=1000;
    in >> n >> k;
    ciuruire();
    for(int i = 1; i <= n; i ++)
    {
        bool ok = 0;
        in >> x;

        if(ciur[x])
            u[i]=1;
        else
            u[i] = 0;
    }
    int i = 1, j = 1;
    while(j <= n && i <= n)
    {
        ct+=u[j];

        while(ct > k)
        {
            ct-=u[i];
            i++;
        }

        if(lmax < j - i+1)
        {
            lmax = j - i + 1;
            poz = i;
        }

        j++;

    }

    out << lmax << " " << poz;
    return 0;
}
