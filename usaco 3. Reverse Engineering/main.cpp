#include <iostream>
#include <cstring>

using namespace std;

char m[101][101];
int v[101];

int main()
{
    int n, a, i, j, l;
    cin >> n >> a;
    for(i = 1; i <= a; i++)
    {
        cin.get();
        for(j = 1; j <= n; j++)
            cin.get(m[i][j]);
        cin >> v[i];
    }
    for(i = 1; i <= a; i++)
    {
        for(j = i + 1; j <= a; j++)
        {
            l = memcmp(m[i], m[j], sizeof(m[i]));
            if(l == 0 && v[i] != v[j])
                break;
        }
        if(j != a+1)
            break;
    }
    if(i != a+1)
        cout << "LIE" << '\n';
    else
        cout << "OK" << '\n';
    return 0;
}
