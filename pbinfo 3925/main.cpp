#include <iostream>

using namespace std;

int main()
{
    long long n, c, r, nr;
    cin >> n >> c >> r;
    nr = (n/c)*c;
    nr += r;
    if(nr > n)
        cout << nr;
    else
        cout << nr+c;
    return 0;
}
