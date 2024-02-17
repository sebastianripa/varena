#include <iostream>

using namespace std;

int v[1000001];

int main()
{
    int n, mini = 1000000001, i, j, l = -1;
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> v[i];
    for(i = 1; i <= n; i++)
    {
        l = -1;
        for(j = i + 1; j <= n; j++)
        {
            if(v[i] > v[j])
                l = j;
        }
        for(j = i-1; j >= 1; j--)
        {
            if(v[i] > v[j] && i-j+1 >= l-i+1)
                l = j;
        }
        cout << l << ' ';
    }
    return 0;
}
