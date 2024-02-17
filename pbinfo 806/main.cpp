#include <iostream>

using namespace std;

int v[60];

int f(int n)
{
    if(n == 1)
        return 1;
    else if(n%2 == 0)
        return 1 + f(n-1);
    else
        return 1 + 2*f(n-2);
}


int main()
{
    int n, i, x = 2, cnt = 2;
    cin >> n;
    v[1] = 1;
    v[2] = 2;
    while(f(x) <= n)
    {
        x++;
        v[x] = f(x);
    }
    for(i = x-1; i >= 1; i--)
        cout << v[i] << ' ';
    return 0;
}
