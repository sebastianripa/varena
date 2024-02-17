#include <iostream>

using namespace std;

int main()
{
    int n, nr1 = 0, nrc = 0, cn;
    cin >> n;
    cn = n;
    while(cn)
    {
        if(cn%10 == 1)
            nr1++;
        nrc++;
        cn /= 10;
    }
    cn = n;
    cout << nrc-1 << '\n' << nr1 << '\n';
    while(cn)
    {
        if(cn%10 != 1 && cn%10 != 0)
            cout << cn%10;
        cn /= 10;
    }
    while(nr1)
    {
        cout << 1;
        nr1--;
    }
    return 0;
}
