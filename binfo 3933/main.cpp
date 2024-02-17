#include <iostream>

using namespace std;

int main()
{
    int n, nr0 = 0, nr1 = 0;
    cin >> n;
    while(n)
    {
        if(n%10 == 1)
            nr1++;
        else if(n%10 == 0)
            nr0++;
        else
        {
            cout << "nu";
            break;
        }
        n /= 10;
    }
    if(n == 0)
    {
        if(nr1 > 0 && nr0 > 0)
            cout << "da";
        else
            cout << "nu";
    }
    return 0;
}
