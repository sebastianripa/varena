#include <bits/stdc++.h>

using namespace std;

ifstream fin ("cufar.in");
ofstream fout ("cufar.out");

pair <long long, long long> ciur[1000005];

void p()
{
    int i, j;
    ciur[0].first = 1;
    ciur[1].first = 1;
    for(i = 2; i <= 1000; i++)
    {
        if(ciur[i].first == 0)
        {
            for(j = i*i; j <= 1000000; j += i)
            {
                ciur[j].first = 1;
                if(ciur[j].second == 0)
                    ciur[j].second = i;
            }
            ciur[i].second = i;
        }
    }
}

bool isPrime(int n)
{
    int i;
    for(i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}

void sir()
{
    int i;
    for(i = 1001; i <= 1000000; i += 2)
    {
        if(ciur[i].first == 0)
            ciur[i].second = i;
    }
}

long long kdivp(long long n, long long k)
{
    long long d = 2, cn;
    while(k)
    {
        d = ciur[n].second;
        cn = n;
        while(n%ciur[cn].second == 0)
            n /= ciur[cn].second;
        k--;
    }
    return d;
}

int main()
{
    long long c, n, x, k, i, s = 0;
    fin >> c >> n;
    p();
    sir();
    if(c == 1)
    {
        fin >> x >> k;
        fout << kdivp(x, k);
    }
    else
    {
        for(i = 1; i <= n; i++)
        {
            fin >> x >> k;
            s += kdivp(x, k);
        }
        fout << s;
    }
    return 0;
}
