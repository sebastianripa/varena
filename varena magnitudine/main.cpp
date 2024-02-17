#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin ("magnitudine.in");
ofstream fout ("magnitudine.out");

int sorted[30];

int main()
{
    long long n, k, idx = 0;
    fin >> n >> k;
    while(n != 0)
    {
        sorted[idx] = n % 10;
        n /= 10;
        idx ++;
    }
    if(idx == 1)
    {
        fout << 0 << "\n";
        return 0;
    }
    sort(sorted, sorted + idx);
    if(k == 0) fout << sorted[idx - 1] - sorted[0] << "\n";
    if(k == 1) fout << min(sorted[idx - 1] - sorted[1], sorted[idx - 2] - sorted[0]) << "\n";
    if(k == 2)
    {
        if(idx <= 2)
        {
            fout << 0 << "\n";
            return 0;
        }
        fout << min(min(sorted[idx - 1] - sorted[2], sorted[idx - 3] - sorted[0]), sorted[idx - 2] - sorted[1]) << "\n";
    }
    return 0;
}
