#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, a, b, i, j, nr = 1, cb, nrp = 0;
    cin >> t;
    for(i = 1; i <= t; i++)
    {
        cin >> a >> b;
        cb = b;
        while(cb)
        {
            nr *= 10;
            nrp += 9;
            cb /= 10;
        }
        nr /= 10;
        nrp -= 9;
        for(i = nr; i <= b; i++)
        {

        }
    }
    return 0;
}
