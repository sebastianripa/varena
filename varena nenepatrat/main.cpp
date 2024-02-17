#include <fstream>

using namespace std;

ifstream cin ("nenepatrat.in");
ofstream cout ("nenepatrat.out");

int main()
{
    unsigned long long n;
    cin >> n;
    unsigned long long se = 1, nrd = 0, s2e = 1, nrd2 = 0, f = 2;
    while(n != 1) {
        int e = 0;
        while(n%f == 0) {
            n /= f;
            e++;
        }
        if(e) {
            se *= (e+1);
            s2e *= (e*2+1);
        }
        f++;
        if(n > 1 && f*f > n)
            f = n;
    }
    cout << (s2e + 1)/2 - se;
    return 0;
}
