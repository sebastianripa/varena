#include <bits/stdc++.h>

using namespace std;

ifstream fin ("maxarea.in");
ofstream fout ("maxarea.out");

int v[1000001];

int main()
{
    int n, i, mini = 15001, j, maxi = 0, s = 0;
    fin >> n;
    for(i = 1; i <= n; i++)
        fin >> v[i];
    for(i = 1; i <= n; i++)
    {
        mini = v[i];
        for(j = i; j <= n; j++)
        {
            if(mini > v[j])
                mini = v[j];
            s = mini*(j-i+1);
            if(maxi < s)
                maxi = s;
        }
    }
    fout << maxi;
    return 0;
}
