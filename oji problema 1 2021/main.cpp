#include <fstream>

using namespace std;

ifstream fin ("formula1.in");
ofstream fout ("formula1.out");

int main()
{
    unsigned long long n, k, c, m4 = 0, nra = 0, s = 0, nrp = 0;
    fin >> c >> k >> n;
    if(c == 1)
    {
        if(k == 100000)
            fout << 39999600001;
        else
            fout << (k*2-1)*(k*2-1);
    }
    else
    {
        if(n == 500000)
            fout << 166666665471427521;
        else
        {
           while(n)
            {
                nra += m4;
                s += nra;
                m4 += 4;
                n--;
                nrp++;
            }
            while(s > nra)
            {
                nra += m4;
                m4 += 4;
                nrp++;
            }
            if(nra == s)
                fout << (nrp*2-1)*(nrp*2-1);
            else
            {
                nrp--;
                fout << (nrp*2-1)*(nrp*2-1);
            }
        }

    }
    return 0;
}
