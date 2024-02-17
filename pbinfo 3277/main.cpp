#include <bits/stdc++.h>

using namespace std;

int const N = 180;

int ma[N][N];
int verif[N][N];
/// verif[i][j] = lungimea minima a drumului de la (startx, starty) la (i, j);
queue <pair<int, int>> q;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n;
bool isInside(int x, int y)
{
    if(x >= 1 and y >= 1 and x <= n and y <= n)
        return true;
    return false;
}

void Lee(int startx, int starty)
{
    q.push({startx, starty});
    verif[startx][starty] = 1;
    while(!q.empty()) // cat timp coada nu e goala
    {
        pair<int, int> primul = q.front(); // salvam primul element
        q.pop(); // eliminam primul element
        for(int d = 0; d < 4; d ++)
        {
            int x = primul.first + dx[d];
            int y = primul.second+ dy[d];
            if(!verif[x][y] and !ma[x][y] && isInside(x, y) == true) // daca nu am trecu prin el si nu e obstacol
            {
                verif[x][y] = verif[primul.first][primul.second] + 1;
                q.push({x, y});
            }
        }
    }
}

int main()
{
    int n, m, i, j, x, y;
    cin >> n >> m;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
            cin >> ma[i][j];
    }
    cin >> x >> y;
    Lee(x, y);
    return 0;
}
