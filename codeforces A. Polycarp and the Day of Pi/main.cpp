#include <iostream>

using namespace std;

int v[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4, 6, 2, 6, 4, 3, 3, 8, 3, 2, 7, 9};
char p[31];

int main()
{
    int t, i, j, ans = 0;
    cin >> t;
    while(t--)
    {
        ans = 0;
        cin >> p;
        for(i = 0; i < 30; i++)
        {
            if(p[i] - 48 == v[i])
                ans++;
            else
                break;
        }
        cout << ans << '\n';
    }
    return 0;
}
