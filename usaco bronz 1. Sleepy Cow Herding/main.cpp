#include <bits/stdc++.h>
#define cin fin
#define cout fout

using namespace std;

ifstream fin ("herding.in");
ofstream fout ("herding.out");

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if(b - a == 2)
        cout << "1\n";
    else if(c - b == 2)
        cout << "1\n";
    else if(c - a == 2)
        cout << "0\n";
    else
        cout << "2\n";
    if(b - a > c - b)
    return 0;
}
