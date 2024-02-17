#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("abc.in");
ofstream fout ("abc.out");

int main()
{
    long n, i, l, f['z' - 'a' + 1] = {0};
    fin >> n >> l;

    char c, j;

    for (i = 0; i < l; i++)
    {
        fin >> c;
        f[c - 'a']++;
    }

    for(j = 'a'; j <= 'z'; j++)
    {
        while(f[j - 'a'] > 0)
        {
            fout << j;
            f[j - 'a']--;
        }
    }

    for(i = l; i < n; i++)
    {
        fin >> c;
        fout << c;
    }

    return 0;
}
