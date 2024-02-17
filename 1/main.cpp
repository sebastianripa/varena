#include <iostream>

using namespace std;

int main()
{
    int n, i;
    bool ok = false;
    cin >> n;
    for(i = 2; i*i <= n; i++)
    {
        if(n%i == 0 && ok == false)
        {
            cout << "Numarul nu este prim";
            ok = true;
        }
    }
    if(ok == false)
        cout << "Numarul este prim";
    return 0;
}
