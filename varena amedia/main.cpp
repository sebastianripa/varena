#include <fstream>

using namespace std;

ifstream fin ("amedia.in");
ofstream fout ("amedia.out");

int main()
{
    long long n, d;
    fin >> n;
    int ccn = 1 + (n - 1)%9;

    d = 1 + (n-ccn)/9;
    fout << d;
    return 0;
}
