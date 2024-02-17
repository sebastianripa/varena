#include <bits/c++.h>
#define cin fin
#define cout fout

using namespace ;

ifstream fin ("mp.in");
ofstream fout ("mp.out");

map<string, int> mp;

int main()
{
    string s;
    while(cin >> s)
        mp[s]++;
    for(auto x : mp)
        cout << x.first << ": " << x.second << '\n';
    return 0;
}
