#include <iostream>

using namespace std;

long long v[200005], maxi;
bool ok = false, ok1 = false;
pair <int, int> aparitii[1000000005];

void vreset()
{
    int i;
    for(i = 1; i <= maxi; i++)
    {
        aparitii[i].first = 0;
        aparitii[i].second = 0;
    }
}

int main()
{
    long long t, n, k, s, f, i, j;
    cin >> t;
    for(j = 1; j <= t; j++)
    {
        maxi = 0;
        cin >> n >> k;
        for(i = 1; i <= n; i++)
            cin >> v[i];
        for(i = 1; i <= n; i++)
        {
            if(aparitii[v[i]].first == 0)
                aparitii[v[i]].first = i;
            else
                aparitii[v[i]].second = i;
            maxi = max(v[i], maxi);
        }

        for(i = 1; i <= k; i++)
        {
            cin >> s >> f;
            if((aparitii[s].first < aparitii[f].second or aparitii[s].first < aparitii[f].first) and aparitii[s].first != 0 and aparitii[f].first != 0)
                    cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
        vreset();
    }
    return 0;
}
