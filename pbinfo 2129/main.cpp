#include <bits/stdc++.h>
using namespace std;
ifstream fin("prime1.in");
ofstream fout("prime1.out");
int a[100] , n , catefib , catec , catep;
int prim(int n)
{
    if(n == 0 || n == 1) return 0;
    if(n == 2) return 1;
    if(n % 2 == 0) return 0;
    for(int i = 3 ; i * i <= n ; i += 2) if(n % i == 0) return 0;
    return 1;
}
int cb(int x)
{
    int st = 0 , dr = 35 , poz = -1;
    while(st <= dr)
    {
        int m =(st + dr)/2;
        if(x <= a[m])
        {
             poz = m;
             dr = m - 1;
        }
        else st = m + 1;
    }
    if(a[poz] == x) return 1;
    else return 0;
}
int nrcif(long long n)
{
    int c = 0;
    while(n)
    {
        n /= 10;
        c++;
    }
    return c;
}
int eco(long long n)
{
    long long d = 2 , cnt = 0;
    long long aux = n;
    while(n > 1)
    {
        int p = 0;
        while(n % d == 0) p++ , n /= d;
        if(p > 1) cnt = cnt + nrcif(p) + nrcif(d);
        else if(p == 1) cnt = cnt + nrcif(d);
        d++;
        if(d*d > n) d = n;
    }
    if(nrcif(aux) > cnt) return 1;
    else return 0;
}
int num(int n)
{
    if(n % 2 == 0) return 0;
    else if(prim(n - 2)) return 0;
    return 1;
}
int main()
{
    a[1] = 1;
    a[2] = 1;
    for(int i = 3 ; i <= 35 ; i++)
        a[i] = a[i-1] + a[i-2];
    long long n , cer , x;
    fin >> cer >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        fin >> x;
        if(cb(x) && prim(x)) catefib++;
        if(eco(x)) catec++;
        if(num(x)) catep++;
    }
    if(cer == 1) fout << catefib;
    if(cer == 2) fout << catec;
    if(cer == 3) fout << catep;
}
