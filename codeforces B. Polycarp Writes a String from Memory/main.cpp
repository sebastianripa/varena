#include <iostream>

using namespace std;

bool v[30];

void vreset()
{
    int i;
    for(i = 1; i <= 29; i++)
        v[i] = 0;
}

int main()
{
    int t, i, j, cnt, nrl = 0;
    char c, l;
    cin >> t;
    cin.get(c);
    for(j = 1; j <= t; j++)
    {
        vreset();
        nrl = 0;
        while(cin.get(l) && l != '\n')
        {
            cnt = l - 96;
            if(v[cnt] == 0)
            {
                if(nrl%3 == 0)
                    vreset();
                nrl++;
            }
            v[cnt] = 1;
        }
        if(nrl%3 == 0)
            cout << nrl/3 << '\n';
        else
            cout << nrl/3+1 << '\n';
    }
    return 0;
}
