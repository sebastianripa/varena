#include <bits/stdc++.h>

using namespace std;

ifstream fin ("paint.in");
ofstream fout ("paint.out");

string v, v2;
int idx[26];

int main()
{
    /*int n, k, i, nrl = 0, j, nrlc = 0;
    fin >> n >> k;
    fin.get(v[1]);
    for(i = 1; i <= n; i++)
    {
        j = 1;
        while(fin.get(v[j]) && (v[j] != ' ' && v[j] != '\n'))
        {
            j++;
            nrl++;
        }
        j--;
        if(nrl > k)
        {
        fout << '\n';
            nrl = 0;
            nrl += j;
            for(j = 1; j <= nrl; j++)
                fout << v[j];
        }
        else
        {
            if(i != 1)
                fout << ' ';
            nrlc = j;
            for(j = 1; j <= nrlc; j++)
                fout << v[j];
        }
        long long n, nr, i, mini = 10000000000, j;
        fin >> n;
        for(i = 1; i <= n-1; i++)
            fin >> v[i];
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
                vf[j] = 0;
            vf[i]++;
            nr = i;
            for(j = 1; j <= n-1; j++)
            {
                nr = v[j] - nr;
                if(nr > 0 && nr <= n)
                    vf[nr]++;
            }
            for(j = 1; j <= n; j++)
            {
                if(vf[j] != 1)
                    break;
            }
            if(j == n+1)
            {
                fout << i << ' ';
                nr = i;
                for(j = 1; j <= n-1; j++)
                {
                    nr = v[j] - nr;
                    if(j == n-1)
                        fout << nr << '\n';
                    else
                        fout << nr << ' ';
                }
                break;
            }
        }
        char c;
        int i, j = 1, nre = 0, nra = 1, nre2 = 0;
        cin >> v >> v2;
        nre = 26;
        nre2 = v2.length();
        for(int i = 0; i < nre; i ++)
            idx[v[i]-'a'] = i;
        for(i = 1; i < nre2; i++)
        {
            if(idx[v2[i]-'a'] <= idx[v2[i-1]-'a'])
                nra++;
        }
        cout << nra << '\n';*/
        int a1, b1, a2, b2, i, nrf = 0;
        fin >> a1 >> b1 >> a2 >> b2;
        for(i = 0; i <= 100; i++)
        {
            if(i >= a1 && i < b1)
                nrf++;
            else if(i >= a2 && i < b2)
                nrf++;
        }
        fout << nrf << '\n';
        return 0;
    }
