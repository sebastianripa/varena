#include <iostream>

using namespace std;

char c[200005];

int main()
{
    int t, n, i, j, ans = 0, mans = 0;
    char l;
    cin >> t;
    while(t--)
    {
        mans = 0;
        cin >> n >> l;
        cin >> c;
        if(l == 'g')
            cout << 0 << '\n';
        else
        {
            for(i = 0; i < n; i++)
            {
                ans = 0;
                if(c[i] == l)
                {
                    for(j = i + 1; c[j] != 'g'; j++)
                    {
                        if(j == n)
                            j = ;
                        ans++;
                    }
                    ans++;
                }
                mans = max(ans, mans);
            }
            cout << mans << '\n';
        }
    }
    return 0;
}
