#include <iostream>

using namespace std;

int v[1000001], vb[1001];

int main()
{
    int i = 1, n;
    while(cin >> v[i])
    {
        i++;
        n++;
    }
    sort(v+1, v+n+1);
    for(i = 2; i <= n; i++)
    {
        if(v[i] == v[i-1])
    }
    return 0;
}
