#include <iostream>

using namespace std;

int x, y;

void rez(int n, int e1)
{
    int e;
    e = e1 + 2*n;
    if(e < y)
        rez(n + 1, e);
    cout << e << ' ';
    return;
}

int main()
{
    int i, n = 1, e = 1;
    cin >> x >> y;
    while(e <= x)
    {
        e = e + 2*n;
        n++;
    }
    rez(n - 1, x);
    cout << x;
    return 0;
}
