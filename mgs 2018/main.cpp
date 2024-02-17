#include <iostream>

using namespace std;

///problema 2

bool isDP(int n, int nrc)
{
    int i, ogl1 = 0, ogl2 = 0, cnrc = nrc, cn = n, p = 1;
    while(nrc > cnrc/2)
    {
        ogl1 = ogl1*10 + n%10;
        n /= 10;
        nrc--;
        p *= 10;
    }
    while(nrc > 0)
    {
        ogl2 = ogl2*10 + n%10;
        n /= 10;
        nrc--;
    }
    if(ogl1 == cn%p && ogl2 == cn/p)
        return true;
    else
        return false;
}

int main()
{
    int k, d, ck, m = 1, i, cm, ans = 0;
    cin >> k >> d;
    ck = k;
    while(ck--)
        m *= 10;
    cm = m-1;
    m /= 10;
    for(i = m; i <= cm; i++)
    {
        if(isDP(i, k) && i%d == 0)
            ans++;
    }
    cout << ans;
    return 0;
}

///problema 1

/*
int main()
{
    int z1, l1, a1, z2, l2, a2, nrz1, nrz2, n = 5, nrz9 = 693610, d, ans, zs1, zs2;
    cin >> z1;
    cin.get();
    cin >> l1;
    cin.get();
    cin >> a1;
    cin.get();
    cin >> z2;
    cin.get();
    cin >> l2;
    cin.get();
    cin >> a2;
    nrz1 = z1;
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
    zs1 = (nrz1 - nrz9-1)%7;
    ans = (nrz2 - nrz1)/7*2;
    zs2 = ((nrz2 - nrz1)%7 + zs1)%7;
    if((zs1 == 5 || zs1 == 6) && (zs2 == 5 || zs2 == 6))
    {
        if(zs1 == zs2)
            ans++;
        else
            ans += 2;
    }
    else if((zs1 == 5 || zs1 == 6) || (zs2 == 5 || zs2 == 6))
        ans++;
    cout << ans;
    return 0;
}
*/
