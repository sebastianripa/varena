#include <iostream>

using namespace std;

long long v[100005], s[100005];

int main()
{
    int n;
    cin >> n;
    for(long long i = 1; i <= n; i++)
        cin >> v[i];
    s[2] = v[1];
    s[n-1] = v[n];
    if(n%2 == 0)
    {
        for(long long i = 2; i < n; i += 2)
            s[i+2] = v[i+1] - s[i];
        for(long long i = n-1; i > 1; i--)
            s[i-2] = v[i-1] - s[i];
    }
    else
    {
        for(long long i = 2; i < n-1; i += 2)
            s[i+2] = v[i+1] - s[i];
        for(long long i = n; i > 1; i--)
            s[i-2] = v[i-1] - s[i];
    }
    for(long long i = 1; i <= n; i++)
        cout << s[i] << ' ';
    return 0;
}
