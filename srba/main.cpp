#include <iostream>

using namespace std;

pair <int, int> v[1000005];
int v[1000005];

int main()
{
    int n, i, j, mini = 0, mdif = 0, dif, st, dr, lastst, last;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v + 1, v + n + 1);

    return 0;
}
