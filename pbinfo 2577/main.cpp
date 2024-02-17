#include <iostream>

using namespace std;

int main()
{
    int64_t n, x, b;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x >> b;
        x >>= b;
        cout << (x&1);
    }
    return 0;
}
