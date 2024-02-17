#include <iostream>

using namespace std;

int main()
{
    long long t, ia, ib, iF, ja, jb, jF, i, j, k, nrp = 0;
    cin >> t;
    for(k = 1; k <= t; k++)
    {
        nrp = 0;
        cin >> ia >> ja >> ib >> jb >> iF >> jF;
        if(ia == iF || ib == iF)
        {
            if(ia == iF && iF == ib)
            {
                if(jF > ja && jF > jb)
                    nrp = max(ja, jb) - min(ja, jb);
                else if(jF < ja && jF < jb)
                    nrp = max(ja, jb) - min(ja, jb);
                else
                {
                    nrp += 2;
                    nrp += max(ja, jb) - min(ja, jb);
                }
            }
            else
            {
                nrp += max(ia, ib) - min(ia, ib);
                nrp += max(ja, jb) - min(ja, jb);
            }
            cout << nrp << '\n';
        }
        else if(ja == jF || jb == jF)
        {
            if(ja == jF && jF == jb)
            {
                if(iF > ia && iF > ib)
                    nrp = max(ia, ib) - min(ia, ib);
                else if(iF < ia && iF < ib)
                    nrp = max(ia, ib) - min(ia, ib);
                else
                {
                    nrp += 2;
                    nrp += max(ia, ib) - min(ia, ib);
                }
            }
            else
            {
                nrp += max(ja, jb) - min(ja, jb);
                nrp += max(ia, ib) - min(ia, ib);
            }
            cout << nrp << '\n';
        }
        else if(ia == ib)
        {
            nrp += max(ja, jb) - min(ja, jb);
            cout << nrp << '\n';
        }
        else if(ja == jb)
        {
            nrp += max(ia, ib) - min(ia, ib);
            cout << nrp << '\n';
        }
        else
        {
            nrp += max(ia, ib) - min(ia, ib);
            nrp += max(ja, jb) - min(ja, jb);
            cout << nrp << '\n';
        }
    }
    return 0;
}
