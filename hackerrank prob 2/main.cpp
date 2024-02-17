#include <bits/stdc++.h>

using namespace std;

long long v[100005], v1[100005];
pair <int, int> p[100005];

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

int main()
{
    unsigned long long q, i, mpf = 1, nrpf = 0, j = 2;
    cin >> q;
    for(i = 1; i <= q; i++)
    {
        j = 2;
        mpf = 1;
        nrpf = 0;
        cin >> v[i];
        while(v[i] >= mpf)
        {
            if(j == 2)
            {
                mpf *= j;
                nrpf++;
                j++;
            }
            else
            {
                while(!isPrime(j))
                    j += 2;
                mpf *= j;
                j += 2;
                nrpf++;
            }
        }
        cout << nrpf - 1 << '\n';
    }
    return 0;
}
