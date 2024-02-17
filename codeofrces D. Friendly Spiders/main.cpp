#include <iostream>

using namespace std;

int fn, ans = 0, lvl1 = 0, lvl2 = 0;
int v[300005];
queue <int> q;

int gcd(int a, int b) {
    int r = a%b;
    while(b) {
        a = b;
        b = r;
        r = a%b;
    }
    return a;
}

void bfs(int st) {
    q.push(st);
    while(!q.empty()) {
        q.pop();
        vf[st] = 1;
        if(lvl1 == 0) {
            lvl1 = lvl2;
            lvl2 = 0;
            ans++;
        }
        for(int i = 1; i <= n; i++) {
            if(v[i] != v[st] && gcd(v[i], v[st]) > 1) {
                lvl2++;
                q.push(i);
            }
        }
        lvl1--;
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    int st;
    cin >> st >> fn;
    bfs(st);
    return 0;
}
