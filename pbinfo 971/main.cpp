#include <iostream>

using namespace std;

int nrDivizori (int n)
{
    int i, nrd = 0;
    for(i = 2; i <= n/2; i++)
    {
        if(n%i == 0)
            nrd++;
    }
    return nrd;
}

int main()
{
    long long n, x, cnm = 0, i;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> x;
        if(nrDivizori(x)%2 == 1 || x == 1)
            cnm += x*3;
        else if(nrDivizori(x) != 0)
            cnm += x;
    }
    cout << cnm;
    return 0;
}
