#include <iostream>

using namespace std;

int v[100001];

int sum(int n)
{
    if(n == 0)
        return n;
    return v[n] + sum(n-1);
}

int main()
{
    int n, i;
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> v[i];
    cout << sum(n);
    return 0;
}
