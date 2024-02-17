#include <iostream>

using namespace std;

char v[50];

int main()
{
    int t, s = 0, i, j, ip;
    char c;
    cin >> t;
    for(j = 1; j <= t; j++)
    {
        s = 0;
        for(i = 1; i <= 26; i++)
            cin >> v[i];
        cin >> c;
        for(i = 1; i <= 26; i++)
        {
            if(v[i] == c)
            {
                ip = i;
                break;
            }
        }
        while(cin.get(c))
        {
            if(c == '\n')
                break;
            for(i = 1; i <= 26; i++)
            {
                if(v[i] == c)
                {
                    s += (max(ip, i) - min(ip, i));
                    ip = i;
                    break;
                }
            }
        }
        cout << s << '\n';
    }
    return 0;
}
