#include <bits/stdc++.h>
#define cin fin
#define cout fout

using namespace std;

ifstream fin ("mp.in");
ofstream fout ("mp.out");

vector<string> v;
map<string, vector<string>> mp;
vector<vector<string>> ans;

void groupAnag()
{
    for(auto x : v)
    {
        string srt = x;
        sort(srt.begin(), srt.end());
        mp[srt].push_back(x);
    }
    for(auto x : mp)
        ans.push_back(x.second);
    for(auto x : ans)
    {
        for(auto y : x)
            cout << y << ' ';
        cout << '\n';
    }
}

int main()
{
    string s;
    while(cin >> s)
        v.push_back(s);
    groupAnag();
    return 0;
}
