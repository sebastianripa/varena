#include <bits/stdc++.h>

using namespace std;

ifstream fin ("algebra.in");
ofstream fout ("algebra.out");

bool isPrime(long long n)
{
    long long i;
    for(i = 2; i*i < n; i++)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}

int desc(int n)
{
    int d = 2;
    while(n > 1)
    {
        while(n%d == 0)
            n /= d;
        d++;
        if(isPrime(n))
        {
            d = n;
            n /= n;
        }
    }
    return d;
}

long long put(long long n)
{
    long long pwr = 1;
    while(n)
    {
        pwr *= 10;
        n--;
    }
    return pwr;
}

int main()
{
    long long a, b, s, ca = 0, cb, pwr;
    char c;
    fin >> c;
    if(c == 'D')
    {
        fin >> a >> b;
        while(a && b)
        {
            if(a > b)
                a %= b;
            else
                b %= a;
        }
        fout << a + b;
    }
    else if(c == 'M')
    {
        fin >> a >> b;
        ca = a;
        cb = b;
        while(a != b)
        {
            if(a > b)
                a -= b;
            else if(a < b)
                b -= a;
        }
        fout << (ca*cb)/a;
    }
    else if(c == 'K')
    {
        fin >> a >> b >> s;
        if(a%s == 0)
            fout << b/s - a/s + 1;
        else
            fout << b/s - a/s;
    }
    else if(c == 'P')
    {
        fin >> a;
        fout << desc(a);
    }
    else if(c == 'S')
    {
        fin >> a >> b;
        pwr = put(b);
        while((a*10)/pwr > 0)
        {
            if(ca < a%pwr)
                ca = a%pwr;
            a /= 10;
        }
        fout << ca;
    }
    return 0;
}
