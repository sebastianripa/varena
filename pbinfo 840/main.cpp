#include <bits/stdc++.h>

using namespace std;

ifstream cin ("croco.in");
ofstream cout ("croco.out");

int main()
{
    int n, m, i, j, v;
    cin >> n >> m;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            cin >> v;
            if(v == 1)
            {
                if((i + j)%2 == 0)
                    cout << "C ";
                else
                    cout << "E ";
            }
            else
                cout << "A ";
        }
    }
    return 0;
}
