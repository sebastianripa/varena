#include <iostream>

using namespace std;

int main()
{
    long long n, ogc, c;
    cin >> n;
    ogc = n%10;
    n /= 10;
    while(n)
    {
        if(ogc %2 == (n%10)%2)
            break;
        ogc = n%10;
        n /= 10;
    }
    if(n == 0)
        cout << "da";
    else
        cout << "nu";
    return 0;
}
