#include <iostream>

using namespace std;

int main()
{
    int t, a, b, i;
    char c;
    cin >> t;
    for(i = 1; i <= t; i++)
    {
        cin >> a;
        cin.get(c);
        cin >> b;
        cout << a + b << '\n';
    }
    return 0;
}
