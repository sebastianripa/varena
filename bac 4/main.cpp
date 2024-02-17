#include <iostream>

using namespace std;

int v[101];

int main()
{
    int n, x, i = 0;
    char c = ' ';
    while(c != '\n')
    {
        i++;
        cin >> v[i];
        cin.get(c);
    }
    cin >> x;
    for(n = 1; n <= i; n++)
    {
        if(x == v[i])
        {
            cout << "DA";
            return 0;
        }
    }
    cout << "NU";
    return 0;
}
