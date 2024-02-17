#include <fstream>

using namespace std;

ifstream fin ("cutii1.in");
ofstream fout ("cutii1.out");

int main()
{
    int n, t, b;
    cin >> n >> t >> b;
    cout << t%n-1 << " ";

    return 0;
}
