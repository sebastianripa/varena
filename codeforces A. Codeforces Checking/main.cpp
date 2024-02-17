#include <iostream>

using namespace std;

int main()
{
    int t;
    char c;
    cin >> t;
    while(t--)
    {
        cin >> c;
        if(c == 'c')
            cout << "YES" << '\n';
        else if(c == 'o')
            cout << "YES" << '\n';
        else if(c == 'd')
            cout << "YES" << '\n';
        else if(c == 'e')
            cout << "YES" << '\n';
        else if(c == 'f')
            cout << "YES" << '\n';
        else if(c == 'r')
            cout << "YES" << '\n';
        else if(c == 's')
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}
