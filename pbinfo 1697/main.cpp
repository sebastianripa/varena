#include <fstream>

using namespace std;

ifstream fin ("cod1.in");
ofstream fout ("cod1.out");

char v[105];

int main()
{
    int cerinta, n, x = 0, i, j, nrnnd = 0, nrc = 0, sc = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0;
    char c;
    fin >> cerinta >> n;
    fin.get(c);
    for(i = 1; i <= n; i++)
    {
        j = 1;
        nrc = 0;
        sc = 0;
        s1 = 0;
        s2 = 0;
        s3 = 0;
        s4 = 0;
        while(fin >> v[j])
        {
            if(v[j] == '#')
            {
                v[j] = '0';
                break;
            }
            nrc++;
            j++;
        }
        if(cerinta == 1)
        {
            for(i = 1; i <= nrc; i++)
            {
                if(i%2 == 1)
                    s1 += v[i] - '0';
                else
                    s2 += v[i] - '0';
                if(i/3%2 == 0)
                    s3 = s3*10 + (v[i] - '0');
                else
                    s4 = s4*10 + (v[i] - '0');
                sc += (v[i]-'0');
            }
            if((v[nrc]-'0')%2 == 1)
            {
                if(sc%3 != 0)
                {
                    if(v[nrc]-'0' != 5)
                    {
                        if((s3-s4)%7 != 0)
                        {
                            if((s2-s1)%2 != 0)
                            {
                                if((s3-s4)%13 != 0)
                                    nrnnd++;
                            }
                        }
                    }
                }
            }
        }
    }
    if(cerinta == 1)
        fout << nrnnd;
    return 0;
}
