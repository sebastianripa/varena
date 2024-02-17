#include <iostream>

using namespace std;

int m[105][105];

int main()
{
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i != j && i%k != j%k)
                m[i][j] = 1;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            cout << m[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
