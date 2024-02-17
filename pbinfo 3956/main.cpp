#include <iostream>

using namespace std;

int main()
{
    int64_t n, p = 0;
    cin >> n;
    while(n) {
        bool ok = false;
        if(p == 0 || ((n>>p)&1) == 1)
            ok = true;
        int nr = 1LL << p;
        n = (n&(~nr));
        p++;
        if(ok)
            cout << n << ' ';
    }
    return 0;
}
