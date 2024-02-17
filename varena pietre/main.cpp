#include <iostream>

using namespace std;

int cm[105][105], m[105][105];
char v[260];

int main()
{

    int n, m1, p, g, i, j, l1, l2, l, L;
    cin >> n >> m >> p >> g;
    for(i = 1; i <= p; i++)
    {
        cin >> l1 >> l2;
        m[l1][l2] = i;
        cm[l1][l2] = i;
    }
    for(i = 1; i <= g; i++)
    {
        cin >> l1 >> l2;
        m[l1][l2] = -1;
        cm[l1][l2] = -1;
    }
    cin >> v;
    return 0;
}
