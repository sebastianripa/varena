#include <iostream>

using namespace std;

int main()
{
    int x, a, b, y, c, d, m1, m2;
    cin >> x >> a >> b >> y >> c >> d;
    m1 = max(a/x, b/x) - min(a/x, b/x);
    if(min(a, b)%x == 0)
        m1++;
    m2 = max(c/y, d/y) - min(c/y, d/y);
    if(min(c, d)%y == 0)
        m2++;
    if(m1 > m2)
        cout << "Ioana " << m1;
    else if(m2 > m1)
        cout << "Maria " << m2;
    else
        cout << "Egalitate " << m1;
    return 0;
}
