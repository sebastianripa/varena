#include <iostream>

using namespace std;

int vf[20];

int putere(int p)
{
    int p2 = 1;
    while(p)
    {
        p2 *= 2;
        p--;
    }
    return p2;
}

int main()
{
    int n, k, p, nrc = 0, i, r = 0, m = 0, m1 = 0;
    cin >> n >> k >> p;
    p = putere(p);
    for(i = 1; i < n; i++)
    {
        r = i + i/p;
        r %= 4;
        vf[r]++;
    }
    for(i = 1; i < n; i++)
    {
        if(m1 < vf[i])
        {
            m = i;
            m1 = vf[i];

        }
    }
    cout << m;
    return 0;
}
