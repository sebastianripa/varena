#include <iostream>

using namespace std;

char v[11] = "codeforces";

int main()
{
    int t, d = 0, i;
    char c;
    cin >> t;
    while(t--)
    {
        d = 0;
        cin.get();
        for(i = 1; i <= 10; i++)
        {
            cin.get(c);
            if(v[i] != c)
                d++;
        }
        cout << d << '\n';
    }
    return 0;
}
