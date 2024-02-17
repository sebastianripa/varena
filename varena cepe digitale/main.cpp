#include <iostream>

using namespace std;

int va[16], vb[16];

int main()
{
    int a, b, s = 0, i = 1, j = 1, m, n, a10 = 0, b10 = 0;
    cin >> a >> b;
    while(a)
    {
        va[i] = a%2;
        a /= 2;
        i++;
    }
    while(b)
    {
        vb[j] = b%2;
        b /= 2;
        j++;
    }
    while(i >= 1 && j >= 1)
    {
        if(va[i] != va[j])
            break;
        i--;
        j--;
    }
    for(m = i; m >= 1; m--)
        a10 = a10*2 + va[m];
    for(n = i; n >= 1; n--)
        b10 = b10*2 + vb[n];
    cout << a10 + b10;
    return 0;
}
