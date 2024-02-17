#include <iostream>

using namespace std;

int main()
{
    int t, s1 = 0, s2 = 0, i;
    char c1, c2, c3, c4, c5, c6;
    cin >> t;
    for(i = 1; i <= t; i++)
    {
        cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;
        s1 = (c1-48)+(c2-48)+(c3-48);
        s2 = (c4-48)+(c5-48)+(c6-48);
        if(s1 == s2)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}
