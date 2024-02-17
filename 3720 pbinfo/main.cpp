#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin ("aproape.in");
ofstream fout ("aproape.out");

int v[1000];

int main()
{
    long long c, n, nrc = 0, nra = 0, inv = 0, cnt, cn, p = 1, p2 = 1, cnt2, i = 1, cn2, nra2 = 0;
    bool afisat = false;
    fin >> c >> n;
    cn = n;
    if(c == 1)
    {
        if(n == 0)
            fout << 1;
        else
        {
            while(n)
            {
                nrc++;
                n /= 10;
            }
            fout << nrc;
        }
    }
    else if(c == 2)
    {
        if(n == 0)
            fout << 1;
        else
        {
            while(n)
            {
                if(n%10 == 9 || n%10 == 0)
                    nra++;
                else if(n == 1 && nra != 0)
                    nra++;
                else
                    nra += 2;
                n /= 10;
            }
            fout << nra;
        }
    }
    else
    {
        cnt = cn;
        while(n)
        {
            cnt = cn;
            if(n%10 == 9)
            {
                cnt -= p;
                cn2 = cnt;
                p2 = 1;
                while(cnt)
                {
                    cnt2 = cn2;
                    if(cnt%10 == 9)
                    {
                        cnt2 -= p2;
                        v[i++] = cnt2;
                        nra++;
                    }
                    else if(cnt%10 == 0)
                    {
                        cnt2 += p2;
                        v[i++] = cnt2;
                        nra++;
                    }
                    else if(cnt == 1 && nra != 0)
                    {
                        cnt2 += p2;
                        v[i++] = cnt2;
                        nra++;
                    }
                    else
                    {
                        cnt2 -= p2;
                        v[i++] = cnt2;
                        cnt2 = cn2;
                        cnt2 += p2;
                        v[i++] = cnt2;
                        nra += 2;
                    }
                    p2 *= 10;
                    cnt /= 10;
                }
            }
            else if(n%10 == 0)
            {
                cnt -= p;
                cn2 = cnt;
                p2 = 1;
                while(cnt)
                {
                    cnt2 = cn2;
                    if(cnt%10 == 9)
                    {
                        cnt2 -= p2;
                        v[i++] = cnt2;
                        nra++;
                    }
                    else if(cnt%10 == 0)
                    {
                        cnt2 += p2;
                        v[i++] = cnt2;
                        nra++;
                    }
                    else if(cnt == 1 && nra != 0)
                    {
                        cnt2 += p2;
                        v[i++] = cnt2;
                        nra++;
                    }
                    else
                    {
                        cnt2 -= p2;
                        v[i++] = cnt2;
                        cnt2 = cn2;
                        cnt2 += p2;
                        v[i++] = cnt2;
                        nra += 2;
                    }
                    p2 *= 10;
                    cnt /= 10;
                }
            }
            else if(n == 1 && nra != 0)
            {
                cnt -= p;
                cn2 = cnt;
                p2 = 1;
                while(cnt)
                {
                    cnt2 = cn2;
                    if(cnt%10 == 9)
                    {
                        cnt2 -= p2;
                        v[i++] = cnt2;
                        nra++;
                    }
                    else if(cnt%10 == 0)
                    {
                        cnt2 += p2;
                        v[i++] = cnt2;
                        nra++;
                    }
                    else if(cnt == 1 && nra != 0)
                    {
                        cnt2 += p2;
                        v[i++] = cnt2;
                        nra++;
                    }
                    else
                    {
                        cnt2 -= p2;
                        v[i++] = cnt2;
                        cnt2 = cn2;
                        cnt2 += p2;
                        v[i++] = cnt2;
                        nra += 2;
                    }
                    p2 *= 10;
                    cnt /= 10;
                }
            }
            else
            {
                cnt -= p;
                cn2 = cnt;
                p2 = 1;
                while(cnt)
                {
                    cnt2 = cn2;
                    if(cnt%10 == 9)
                    {
                        cnt2 -= p2;
                        v[i++] = cnt2;
                        nra++;
                    }
                    else if(cnt%10 == 0)
                    {
                        cnt2 += p2;
                        v[i++] = cnt2;
                        nra++;
                    }
                    else if(cnt == 1 && nra != 0)
                    {
                        cnt2 += p2;
                        v[i++] = cnt2;
                        nra++;
                    }
                    else
                    {
                        cnt2 -= p2;
                        v[i++] = cnt2;
                        cnt2 = cn2;
                        cnt2 += p2;
                        v[i++] = cnt2;
                        nra += 2;
                    }
                    p2 *= 10;
                    cnt /= 10;
                }
                cnt = cn;
                cnt += p;
                cn2 = cnt;
                p2 = 1;
                cnt -= p;
                cn2 = cnt;
                p2 = 1;
                while(cnt)
                {
                    cnt2 = cn2;
                    if(cnt%10 == 9)
                    {
                        cnt2 -= p2;
                        v[i++] = cnt2;
                        nra++;
                    }
                    else if(cnt%10 == 0)
                    {
                        cnt2 += p2;
                        v[i++] = cnt2;
                        nra++;
                    }
                    else if(cnt == 1 && nra != 0)
                    {
                        cnt2 += p2;
                        v[i++] = cnt2;
                        nra++;
                    }
                    else
                    {
                        cnt2 -= p2;
                        v[i++] = cnt2;
                        cnt2 = cn2;
                        cnt2 += p2;
                        v[i++] = cnt2;
                        nra += 2;
                    }
                    p2 *= 10;
                    cnt /= 10;
                }
            }
            p *= 10;
            n /= 10;
        }
        sort(v+1, v+nra+1);
        for(i = 2; i <= nra; i++)
        {
            if(v[i-1] != v[i])
                nra2++;
            if(v[i-1] != v[i] && i == nra)
                nra2++;
        }
        f  out << nra2;
    }
    return 0;
}
