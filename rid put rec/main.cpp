#include <iostream>

using namespace std;

int c;

int rpr(int x, int b) {
    if(b == 0) {
        return 1;
    } else {
        int y = rpr(x, b/2);
        if(b%2 == 0)
            return (y*y)%c;
        else
            return (y*y*x)%c;
    }
}

int main()
{
    int a, b, ans;
    cin >> a >> b >> c;
    ans = rpr(a, b);
    cout << ans;
    return 0;
}
