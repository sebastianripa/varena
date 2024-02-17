#include <iostream>

using namespace std;

int ePrim(int n)
{
    int i;
    for(i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    if(n%2 == 0)
        n++;
    else
        n += 2;
    while(!ePrim(n))
        n += 2;
    cout << n;
    return 0;
}
