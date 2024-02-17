#include <iostream>

using namespace std;

int main()
{
    int64_t n, p = 1, nr = 0;
    cin >> n;
    while(p <= n) {
        p << 1;
        nr++;
    }
    cout << nr - 1;
    return 0;
}
