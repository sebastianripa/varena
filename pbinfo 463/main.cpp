#include <iostream>

using namespace std;

int fm = 0, v[100001];

void descompunere (int n)
{
    int f, e, nr;
    f = 2;
    while(n != 1)
    {
        while(n%f == 0)
            n /= f;
        if(fm < f)
            fm = f;
        f++;
        if(f*f > n && n > 1)
            f = n;
    }
}

int main()
{
    int n, x, i, em = 0;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> v[i];
        descompunere(v[i]);
    }
    for(i = 1; i <= n; i++)
    {
        if(v[i]%fm == 0)
            em++;
    }
    cout << fm << " " << em;
    return 0;
}
