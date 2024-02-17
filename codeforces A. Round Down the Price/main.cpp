#include <iostream>

using namespace std;

int main()
{
    int t, n, p10 = 1, i;
    cin >> t;
    for(i = 1; i <= t; i++)
    {
        p10 = 1;
        cin >> n;
        while(p10 <= n)
            p10 *= 10;
        p10 /= 10;
        cout << n-p10 << '\n';
    }
    return 0;
}
