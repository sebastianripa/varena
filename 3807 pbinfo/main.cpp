#include <iostream>

using namespace std;

int main()
{
    unsigned long long n, x, s, i, j, p;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        s = 1;
        p = 1;
        cin >> x;
        for(j = 2; j <= x; j++)
        {
            p += j;
            s += p;
        }
        cout << s << ' ';
    }
    return 0;
}
