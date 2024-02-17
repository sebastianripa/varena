#include <iostream>

using namespace std;

int main()
{
    int n, nr = 1, maxi = 2, i, ogmaxi;
    cin >> n;
    if(n == 1)
        cout << 1;
    else
    {
        ogmaxi = 2;
        for(i = 1; i < n; i++)
        {
            if(nr == maxi && maxi != 1)
            {
                ogmaxi = maxi;
                maxi = 1;
            }
            if(nr == maxi && maxi == 1)
                maxi = ogmaxi + 1;
            if(maxi == 1)
                nr--;
            if(maxi != 1)
                nr++;
        }
        cout << nr;
    }

    return 0;
}
