#include <iostream>

using namespace std;

int main()
{
    int n, i, nrc = 0, cn, nrcn;
    cin >> n;
    nrcn = n;
    cn = n;
    while(cn)
    {
        nrc++;
        cn /= 10;
    }
    nrcn -= nrc;
    cout << n;
    for(i = 1; i <= nrcn; i++)
        cout << 0;
    return 0;
}
