#include <iostream>

using namespace std;

int m[100][100];

int main()
{
    int i, j;
    for(i = 1; i <= 3; i++)
    {
        for(j = 1; j <= 3; j++)
        {
            m[i][j] = min(i, j);
            m[i][6-j+1] = m[i][j];
            m[6-i+1][j] = m[i][j];
            m[6-i+1][6-j+1] = m[i][j];
        }
    }
    for(i = 1; i <= 6; i++)
    {
        for(j = 1; j <= 6; j++)
            cout << m[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
