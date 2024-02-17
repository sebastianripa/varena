#include <iostream>

using namespace std;

int ePrim(int n)
{
    int i;
    if(n < 2)
        return false;
    for(i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n, x, nrnp = 0, i;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> x;
        if(ePrim(x))
            nrnp++;
    }
    cout << nrnp;
    return 0;
}
