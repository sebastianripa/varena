#include <bits/stdc++.h>

using namespace std;

ifstream fin ("schi.in");
ofstream fout ("schi.out");

vector <int> bits(30005, 0);
int v[30005], ans[30005];
int n;

void update(int i, int val) {
    while(i <= n) {
        bits[i] += val;
        i += (i&-i);
    }
}

int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++)
        fin >> v[i];
    for(int i = 1; i <= n; i++)
        bits[i] += (i&-i);
    int lg = log2(n);
    for(int i = n; i >= 1; i--) {
        int s = 0, idx = 0;
        for(int j = lg; j >= 0; j--) {
            if(idx + (1<<j) < n && s + bits[idx + (1<<j)] < v[i]) {
                idx += (1<<j);
                s += bits[idx];
            }
        }
        ans[idx+1] = i;
        update(idx+1, -1);
    }
    for(int i = 1; i <= n; i++)
        fout << ans[i] << '\n';
    return 0;
}
