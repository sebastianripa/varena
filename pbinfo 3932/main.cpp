#include <iostream>

using namespace std;

int main()
{
    int n, p = 1, cn;
    bool zf = true;
    cin >> n;
    cn = n;
    while(n)
    {
        if(n%10 == 0 && zf == true)
            p *= 10;
        else
            zf = false;
        n /= 10;
    }
    cout << cn/p;
    return 0;
}
