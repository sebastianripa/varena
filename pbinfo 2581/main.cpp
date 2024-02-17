#include <iostream>

using namespace std;

bool v[1000];

int main()
{
    unsigned long long n, p = 1, i = 0, s = 0, x = 0;
    cin >> n;
    while(p < n) {
        p <<= 1;
        i++;
    }
    p >>= 1;
    i--;
    while(p > 1) {
        if(n >= p) {
            n -= p;
            v[i] = 1;
        }
        i--;
        x++;
        p >>= 1;
    }
    for(unsigned long long j = 0; j <= x; j++) {
        if(!v[j])
            s += (1 << j);
    }
    cout << s;
    return 0;
}
