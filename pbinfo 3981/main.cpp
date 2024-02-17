#include <bits/stdc++.h>

using namespace std;

int DivImpRec(int n, int d = 3)
{
    if(n%2 == 0)
        return DivImpRec(n/2, d);
    if(d > sqrt(n))
        return n;
    if(n%d == 0)
        return DivImpRec(n/d, d);
    else
        return DivImpRec(n, d+2);
}

int main()
{
    int n;
    cin >> n;
    cout << DivImpRec(n);
    return 0;
}
