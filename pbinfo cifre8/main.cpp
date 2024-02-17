#include <iostream>

using namespace std;

int v[30001], vf[10];

bool prime(int n)
{
    int i;
    if(n < 2)
        return false;
    for(i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}

int doi(int n, int c)
{
    int nra = 0;
    while(n)
    {
        if(n%10 == c)
            nra++;
        n /= 10;
    }
    return nra;
}

int main()
{
    int n, c, i, s = 0, nac = 0, a = 0, b = 0, cn, r;
    cin >> n >> c;
    for(i = 1; i <= n; i++)
    {
        cin >> v[i];
        if(prime(v[i]))
            s += v[i];
        nac += doi(v[i], c);
        if((v[i]%10)%2 == 1)
            vf[v[i]%10]++;
    }
    cout << s << '\n' << nac << '\n';
    s = 0;
    for(i = 1; i <= 9; i += 2)
    {
        r = 0;
        if(vf[i] != 0)
        {
            if(a == 0)
                a = vf[i];
            else
            {
                b = vf[i];
                while(b != 0)
                {
                  r = a % b;
                  a = b;
                  b = r;
                }
            }
            s += vf[i];
        }
        if(a == 1)
            break;
    }
    cout << s/a;
    return 0;
}
