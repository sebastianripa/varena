#include <iostream>

using namespace std;

int main()
{
    int n, i, j;
    cin >> n;
    for(j = 1; j <= n; j++)
    {
        for(i = 1; i <= n; i++)
        {
            if(i == j)
                cout << 0 << ' ';
            else
                cout << n-i+1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}
