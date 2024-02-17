#include <bits/stdc++.h>
//#define cin fin
//#define cout fout

using namespace std;

int vf[126], v[126];

int sol(int n, int k)
{
    int i;
    if(k == 1)
    {
        for(i = 1; i <= n/2; i++)
        {
            v[i] = 2;
            cout << 2 << ' ';
        }
        cout << '\n';
        sol(n, k+2);
    }
    else
    {
        for(i = n; i >= k; i++)
        {
            v[i-1] = v[i]*2;
        }
    }
}

int main ()
{
    int n, i, p = 2;
    cin >> n;
    
}