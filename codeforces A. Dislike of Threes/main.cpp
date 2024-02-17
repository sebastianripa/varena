#include <iostream>

using namespace std;

int main()
{
    int t, n, nr = 0, i, j;
    cin >> t;
    for(i = 1; i <= t; i++)
    {
        cin >> n;
        nr = 1;
        if(n == 1)
            cout << 1 << '\n';
        else if(n == 2)
            cout << 2 << '\n';
        else
        {
            for(j = 2; j <= n; j++)
            {
                if((nr+1)%3 != 0 && (nr+1)%10 != 3)
                    nr++;
                else
                {
                    if((nr+2)%3 == 0 || (nr+2)%10 == 3)
                        nr += 2;
                    else
                        nr++;
                    j--;
                }
            }
            cout << nr << '\n';
        }

    }
    return 0;
}
