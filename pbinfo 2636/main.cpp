#include <iostream>

using namespace std;

int main()
{
    long long n, m, s = 0;
    cin >> n >> m;
    cout << max(s, n - m*2) << ' ';
    int i;
    for(i = 0; s < m; i++)
        s += i;
    cout << n-i;
    return 0;
}
