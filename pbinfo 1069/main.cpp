#include <bits/stdc++.h>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
map <int, vector<pair<int, int>>> adj;
vector <int> vl(16, 0);
vector <vector <int>> v();
bool vf[2001];

int main()
{
    int n, m, q, x;
    cin>> n >>> m >> q;
    for(int i = 1; i <= q; i++) {
        cin >> x;
        vl.push_back(x);
    }
    return 0;
}
