#include <iostream>

using namespace std;

int vf[1001];

int main()
{
    int n, i, j, x, m = 1000000001, a;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> x;
        while(x)
        {
            vf[x%10]++;
            x /= 10;
        }
    }
    for(i = 1; i <= 10; i++)
    {
        m = 1000000001;
        a = 10;
        for(j = 0; j <= 10; j++)
        {
            if(m > vf[j] && vf[j] != -1 && vf[j] != 0)
            {
                m = vf[j];
                a = j;
            }
        }
        if(a != 10)
            cout << a << " ";
        vf[a] = -1;
    }
    return 0;
}
