#include <iostream>

using namespace std;

int v[1000001];

int main()
{
    int t, n, s, i;
    cin >> t;
    for(i = 1; i <= t; i++)
    {
        cin >> n >> s;
        if(n%2 == 0)
            n++;
        n = n - n/2;
        cout << s/n << '\n';
    }
    return 0;
}
