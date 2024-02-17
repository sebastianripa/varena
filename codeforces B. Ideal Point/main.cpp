#include <iostream>

using namespace std;

int l[51], r[51], ml[51], mr[51];

int main()
{
    int t, n, k, i, j, m;
    bool ok = false;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(i = 1; i <= n; i++)
        {
            cin >> l[i] >> r[i];
            ml[i] = l[i];
            mr[i] = r[i];
        }
        sort(ml+1, ml+n+1);
        sort(mr+1, mr+n+1);
        for(i = 1; i <= n; i++)
        {
            if(ml[i] > mr[n])
            {
                if(!ok)
                {
                    ok = true;
                    m = i - 1;
                }
                ml[i] = 0;
            }
        }

    }
    return 0;
}
