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
    int n, x, nrnp = 0, i,nrpmax = 0, nrpmin = 1000000000;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> x;
        if(ePrim(x))
        {
            nrnp++;
            if(x < nrpmin)
                nrpmin = x;
            if(x > nrpmax)
                nrpmax = x;
        }
    }
    cout << nrnp << " " << nrpmin << " " << nrpmax;
    return 0;
}
