#include <iostream>

using namespace std;

int main()
{
    int n, nr1 = 0, nr2 = 0, i = 1, j, x = 1, v;
    char c;
    cin >> n;
    while(cin.get(c) == 1)
    {
        x = c - 48;
        if(i%2 == 1)
            nr1++;
        else
            nr2++;
        i++;
    }
    v = nr1 + nr2;
    while(cin.get(c) == 2)
    {
        x = c - 48;

    }
    return 0;
}
