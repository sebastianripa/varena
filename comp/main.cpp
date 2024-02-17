#include <iostream>

using namespace std;

int v1[1000000], v2[1000000];

int main()
{
    int i, n;
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> v1[i];
    for(i = 1; i <= n; i++)
        cin >> v2[i];
    for(i = 1; i <= n; i++)
    {
        if(v1[i] != v2[i])
        {
            cout << v1[i] << ' ' << v2[i] << ' ' << i;
            break;
        }
    }
    return 0;
}
