#include <fstream>

using namespace std;

ifstream fin ("pian.in");
ofstream fout ("pian.out");

int main()
{
    int c, n, a, b, d, i, r;
    cin >> c >> n >> a;
    for(i = 2; i <= n; i++)
    {
        cin >> b;
        if(i == 2)
        {
            while(b != 0)
            {
              r = a % b;
              a = b;
              b = r;
            }
            d = a;
        }
        else
        {
            while(b != 0)
            {
              r = d % b;
              d = b;
              b = r;
            }
        }
    }
    cout << d*n;
    return 0;
}
