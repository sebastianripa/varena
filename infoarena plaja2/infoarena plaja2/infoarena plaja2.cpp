#include <fstream>
#include <cmath>

using namespace std;

ifstream in("plaja2.in");
ofstream out("plaja2.out");

long long n, k, t;

long long v[100005], c[100005];
long long rez;

void funct(int i, int j)
{
    long long st = v[i], dr = v[j];
    while (st < dr)
    {
        int mid = (st + dr) / 2;
        long long a = c[i] + abs(mid - v[i]) * t;
        long long b = c[j] + abs((mid + 1) - v[j]) * t;
        if (abs(a - b) <= t)
            rez = max(rez, max(a, b));
        if (a >= b)
            dr = mid;
        else
            st = mid + 1;
    }
}
int main()
{
    in >> n >> k >> t;
    for (long long i = 1; i <= k; i++)
        in >> v[i] >> c[i];

    rez = max(c[1] + (abs(1 - v[1])) * t, c[k] + (abs(n - v[k])) * t);

    for (long long i = 1; i < k; i++)
        funct(i, i + 1);

    out << rez;
    return 0;
}