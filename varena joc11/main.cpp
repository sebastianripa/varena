#include <bits/stdc++.h>

using namespace std;

ifstream fin ("joc11.in");
ofstream fout ("joc11.out");

int v1[10005], v2[10005], vf[10005];

int nrdiv(int n)
{
    int i, nrd = 0;
    for(i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
            nrd++;
    }
    if(i*i != n)
        nrd++;
    return nrd+2;
}

int main()
{
    int c, n, i = 1, j = 1, m = 1, maxi = 0, x;
    fin >> c >> n;
    if(c == 1)
        fout << nrdiv(n);
    else
    {
        vf[1] = 1;
        while(i < n && j < n)
        {
            if(m%2 == 1)
            {
                x = (m + (i + n)%10)%6 + 1;
                i += x;
                vf[i]++;
            }
            else
            {
                x = ((m + 1)%5 + (i + n)%10)%6 + 1;
                i += x;
                vf[i]++;
            }
            if(i == j)
                j = 1;
            if(i == n)
                break;
            m++;
            while(x == 6)
            {
                if(m%2 == 1)
                {
                    x = (m + (i + n)%10)%6 + 1;
                    i += x;
                    vf[i]++;
                }
                else
                {
                    x = ((m + 1)%5 + (i + n)%10)%6 + 1;
                    i += x;
                    vf[i]++;
                }
                if(i == j)
                    j = 1;
                if(i == n)
                    break;
                m++;
            }
            if(m%2 == 1)
            {
                x = (m + (j + n)%10)%6 + 1;
                j += x;
                vf[j]++;
            }
            else
            {
                x = ((m + 1)%5 + (j + n)%10)%6 + 1;
                j += x;
                vf[j]++;
            }
            if(i == j)
                i = 1;
            if(j == n)
                break;
            m++;
            while(x == 6)
            {
                if(m%2 == 1)
                {
                    x = (m + (i + n)%10)%6 + 1;
                    j += x;
                    vf[j]++;
                }
                else
                {
                    x = ((m + 1)%5 + (i + n)%10)%6 + 1;
                    j += x;
                    vf[j]++;
                }
                if(i == j)
                    i = 1;
                if(j == n)
                    break;
                m++;
            }
        }
        for(i = 1; i <= n; i++)
        {
            if(maxi < vf[i])
                maxi = vf[i];
        }
        fout << maxi;
    }
    return 0;
}
