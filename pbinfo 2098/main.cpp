#include <iostream>

using namespace std;

int v[1005];

int main()
{
    int n, i, maxi = 0, ng = 0, p = 0, in, sf;
    bool poz = false, neg = false;
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> v[i];
    for(i = 1; i <= n; i++)
    {
        if(poz)
        {
            if(ng > p)
            {
                ng--;
                i -= 2;
                if(maxi < ng*2)
                {
                    maxi = ng*2;
                    sf = i;
                }
                else if(maxi == ng*2)
                    sf = i;
                ng = 0;
                p = 0;
                poz = false;
            }
            else if(p == ng+2)
            {
                p -= 2;
                i -= 2;
                if(maxi < ng*2)
                {
                    maxi = ng*2;
                    sf = i;
                }
                else if(maxi == ng*2)
                    sf = i;
                ng = 0;
                p = 0;
                poz = false;
            }
            else
            {
                if(v[i] >= 0)
                    p++;
                else
                    ng++;
            }
        }
        else if(neg)
        {
            if(p > ng)
            {
                p--;
                i -= 2;
                if(maxi < p*2)
                {
                    maxi = p*2;
                    sf = i;
                }
                else if(maxi == p*2)
                    sf = i;
                ng = 0;
                p = 0;
                neg = false;
            }
            else if(n == p+2)
            {
                ng -= 2;
                i -= 2;
                if(maxi < p*2)
                {
                    maxi = p*2;
                    sf = i;
                }
                else if(maxi == p*2)
                    sf = i;
                ng = 0;
                p = 0;
                neg = false;
            }
            else
            {
                if(v[i] >= 0)
                    p++;
                else
                    ng++;
            }
        }
        else
        {
            if(v[i] >= 0)
            {
                p++;
                poz = true;
                in = i;
            }
            else
            {
                ng++;
                neg = true;
                in = i;
            }
        }
    }
    cout << maxi << '\n';
    for(i = in; i <= sf; i++)
        cout << v[i] << ' ';
    return 0;
}
