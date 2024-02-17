#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin ("numar3.in");
ofstream fout ("numar3.out");

int main()
{
    int n, m1 = 10, m2 = 10, m3 = 10, p1, p2, p3, aux, i;
    bool maiMic = false;
    fin >> n;
    char v[n+1], v2[n+1];
    for(i = 1; i <= n; i++)
        fin >> v[i];
    if(v[n] > v[n-1])
    {
        aux = v[n];
        v[n] = v[n-1];
        v[n-1] = aux;
    }
    else
    {
        for(i = 1; i <= n; i++)
        {
            if(m1 > v[i]-48 & i != n)
            {
                m2 = m1;
                p2 = p1;
                m1 = v[i]-48;
                p1 = i;
            }
            else if(m1 == v[i]-48 && i != n)
                p1 = i;
        }
        while(maiMic == false)
        {
            for(i = 1; i <= n; i++)
            {
                if(m1 > v[i]-48)
                {
                    maiMic = true;
                    if(v[i]-48 < m3)
                    {
                        m3 = v[i];
                        p3 = i;
                    }
                    else if(v[i]-48 == m3)
                        p3 = i;
                }
                else if(m2 > v[i]-48)
                {
                    m2 = v[i]-48;
                    p2 = i;
                }
                else if(m2 == v[i]-48)
                    p2 = i;
            }
            if(maiMic == false)
            {
                m1 = m2;
                p1 = p2;
            }

        }
        aux = v[p1];
        v[p1] = v[p2];
        v[p2] = aux;
        sort(v+m1+2, v+n+1);
    }
    for(i = 1; i <= n; i++)
        fout << v[i];
    return 0;
}
