#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    float a, b, c, d;
    float x;
    cin >> a >> b >> c >> d;
    x = (b*c - a*d)/(d - c);
    cout << fixed << setprecision(2) << x;
    return 0;
}
