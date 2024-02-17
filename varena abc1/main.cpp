#include <fstream>
#include <cmath>

using namespace std;

ifstream fin ("abc1.in");
ofstream fout ("abc1.out");

int main()
{
    int a, b, c, bpc, apbpc;
    fin >> a >> b >> c;
    bpc = pow(b, c);
    apbpc = pow(a, bpc);
    fout << apbpc%10;
    return 0;
}
