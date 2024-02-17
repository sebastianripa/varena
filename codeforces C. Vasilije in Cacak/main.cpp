#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        long long n, k, x;
        cin >> n >> k >> x;
        if(k > n) {
            cout << "NO" << '\n';
            continue;
        }
        long long dif = n*(n+1)/2;
        long long dif1 = (n-k)*(n-k+1)/2;
        dif -= dif1;
        dif1 = k*(k+1)/2;
        if(dif >= x && x >= dif1)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}
