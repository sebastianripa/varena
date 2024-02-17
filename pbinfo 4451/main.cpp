#include <iostream>

using namespace std;

int main()
{
    int cer, n, x, a, b, ogx, i, j, cx, cox, r;
    cin >> cer >> n >> ogx;
    for(i = 2; i <= n; i++)
    {
        cin >> x;
        cx = x;
        cox = x;
        r = cx%cox;
        while(r != 0)
        {
            cx = cox;
            cox = r;
            r = cx%cox;
        }
        if(cox != 1)
        {

        }
    }
    return 0;
}
