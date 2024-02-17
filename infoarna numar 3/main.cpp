#include <iostream>

using namespace std;

char v[5000001];

int main()
{
    int n, i;
    char u;
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> v[i];
    u = v[n];
    for(i = n-1; i >= 1; i++)
    {
        if(u > v[i])
        {
            swap(v[i], v[n]);
            break;
        }
    }
    for(i = 1; i <= n; i++)
        cout << v[i];
    return 0;
}
