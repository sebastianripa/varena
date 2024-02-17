#include <iostream>

using namespace std;

int nrzl1 (int a1, int l1, int z1)
{
    int nrz1;
    if(l1 > 2)
    {
        nrz1 += 31 + 28 + (l1-3)*30;
        if(l1 <= 7)
            nrz1 += (l1-1)/2;
        else
            nrz1 += l1/2;
    }
    else if(l1 == 2)
        nrz1 += 31;
    nrz1 += (a1-1)*365 + (a1-1)/4;
    if(a1%4 == 0 && (l1 > 2 || (l1 == 2 && z1 == 29)))
        nrz1++;
    return nrz1;
}

int nrzl2 (int a2, int l2, int z2)
{
    int nrz2;
    nrz2 = z2;
    if(l2 > 2)
    {
        nrz2 += 31 + 28 + (l2-3)*30;
        if(l2 <= 7)
            nrz2 += (l2-2)/2;
        else
            nrz2 += (l2-1)/2;
    }
    else if(l2 == 2)
        nrz2 += 31;
    nrz2 += (a2-1)*365 + (a2-1)/4;
    if(a2%4 == 0 && (l2 > 2 || (l2 == 2 && z2 == 29)))
        nrz2++;
    return nrz2;
}

int date(int d, int i, int nr)
{
    if(i == 1)
    {
        if(nr == 1)
            return nrzl1(d%10000, d/10000%100, d/1000000);
        else
            return nrzl2(d%10000, d/10000%100, d/1000000);
    }
    if(i == 2)
    {
        if(nr == 1)
            return nrzl1(d%10000, d/1000000, d/10000%100);
        else
            return nrzl1(d%10000, d/1000000, d/10000%100);
    }
}

int main()
{
    int d1, d2, i, j, nrz, nrz1, nrz2;
    cin >> d1 >> d2 >> nrz;

    return 0;
}
