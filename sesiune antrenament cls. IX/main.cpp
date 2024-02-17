#include <iostream>

using namespace std;

int v[100001], v2[100001];

int main()
{
    int n, s = 0, k = 1, i;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> v[i];
        v2[i] = v[i];
    }
    while(k <= n)
    {
        s = 0;
        for(i = 1; i <= n; i++)
            v[i] = v2[i];
        if(k == 1)
        {
            for(i = n; i >= k+1; i--)
            {
                if(v[i-1] < v[i])
                {
                    s += v[i] - v[i-1];
                    v[i-1] += v[i] - v[i-1];
                }
            }
        }
        else if(k == n)
        {
            for(i = 2; i <= k; i++)
            {
                if(v[i-1] > v[i])
                {
                    s += v[i-1] - v[i];
                    v[i] += v[i-1] - v[i];
                }
            }
        }
        else
        {
            for(i = n; i >= k+1; i--)
            {
                if(v[i-1] < v[i])
                {
                    s += v[i] - v[i-1];
                    v[i-1] += v[i] - v[i-1];
                }
            }
            for(i = 2; i <= k; i++)
            {
                if(v[i-1] > v[i])
                {
                    s += v[i-1] - v[i];
                    v[i] += v[i-1] - v[i];
                }
            }
        }
        cout << s << ' ';
        k++;
    }
    return 0;
}
