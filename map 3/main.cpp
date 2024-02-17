#include <bits/stdc++.h>
#define cin fin
#define cout fout

using namespace std;

ifstream fin ("mp.in");
ofstream fout ("mp.out");

map<int, vector<string>> mp;
vector<string> v;

int main()
{
    int maxi = 0, x;
    string s;
    while(cin >> s)
    {
        x = s.size();
        mp[x].push_back(s);
        maxi = max(x, maxi);
    }
    vector<vector<string>> st;
    for(auto x : mp)
    {
        if(x.second == mp[maxi])
        {
            for(auto y : x.second)
                cout << y << ' ';
        }
    }
    return 0;
}
