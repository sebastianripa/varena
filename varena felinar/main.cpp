#include <fstream>

using namespace std;

ifstream fin ("felinare.in");
ofstream fout ("felinare.out");

int main()
{
    int n;
    fin >> n;
    if(n%2 == 1)
        fout << n*(n-1)+1;
    else
        fout << n*n-1;
    return 0;
}
