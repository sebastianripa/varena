#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
ifstream fin("seti.in");
ofstream fout("seti.out");
int v[300];
string stv[200005];
bool cmp(string a, string b) {
    for (int i = 0; i < min(a.size(), b.size()); i++) {
        if (a[i] != b[i])
            return v[a[i]] < v[b[i]];
    }
    return a.size() < b.size();
}
int main()
{
    int n = 10;
    for (int i = 1; i <= n; i++) {
        char c;
        fin >> c;
        v[c] = i;
    }
    string str;
    int pos = 0;
    while (fin >> str)
        stv[pos++] = str;
    sort(stv, stv + pos, cmp);
    for (int i = 0; i < pos; i++)
        fout << stv[i] << '\n';
    return 0;
}