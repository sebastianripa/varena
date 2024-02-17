#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin ("vanator.in");
ofstream fout ("vanator.out");

bool ePrim(int n)
{
    int i;
    if(n < 2)
        return false;
    for(i = 2; i <= n/2; i++)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}

int vc[1001], vm[4];

int main()
{
    int n, g, i, s = 0;
    long long k, k1, k2, k3, sm = 0, sb = 0;
    char c;
    fin >> n >> g;
    for(i = 1; i <= n; i++)
        fin >> vc[i];
    sort(vc+1, vc+n+1);
    for(i = n; i >= 1; i--)
    {
        if(!ePrim(vc[i]))
        {
            s += vc[i];
            g--;
            if(g == 0)
                break;
        }
    }
    fin >> k >> k1 >> k2 >> k3;
    if(sm < k1+k2 && k1+k2 <= k)
        sm = k1+k2;
    if(sm < k3+k2 && k3+k2 <= k)
        sm = k3+k2;
    if(sm < k3+k1 && k3+k1 <= k)
        sm = k3+k1;
    if(sm < k1+k2+k3 && k1+k2+k3 <= k)
        sm = k1+k2+k3;
    if(sm < k1 && k1 <= k)
        sm = k1;
    if(sm < k2 && k2 <= k)
        sm = k2;
    if(sm < k3 && k3 <= k)
        sm = k3;
    for(i = 1; i <= 6; i++)
    {
        fin.get(c);
        switch(c)
        {
            case '1':
                sb += 2;
                break;
            case '2':
            case '3':
            case '5':
                sb += 5;
                break;
            case '4':
                sb += 4;
                break;
            case '6':
            case '9':
            case '0':
                sb += 6;
                break;
            case '7':
                sb += 3;
                break;
            case '8':
                sb += 7;
                break;
        }
    }
    fout << s << '\n' << sm << '\n' << sb;
    return 0;
}
