#include <iostream>

using namespace std;

int main()
{
    int n, x, i;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> x;
        cout << "Division ";
        if(x >= 1900)
            cout << 1;
        else if(x >= 1600)
            cout << 2;
        else if(x >= 1400)
            cout << 3;
        else cout << 4;
        cout << '\n';
    }
    return 0;
}
