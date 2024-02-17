
    #include <fstream>
#include <queue>
using namespace std;
ifstream in("alee.in");
ofstream out("alee.out");
int di[4]= {0,0,1,-1};
int dj[4]= {1,-1,0,0};
int ma[185][185],n,m;
int startx,starty,stopx,stopy;
queue < pair < int ,int > > coada;
void citire()
{
    in>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int x,y;
        in>>x>>y;
        ma[x][y]=-1;
    }
    in>>startx>>starty;
    in>>stopx>>stopy;
}
bool functie(int i,int j)
{
    if(i<1 || j<1 || i>n || j>n)
        return false;
    if(ma[i][j]==-1)
        return false;
    return true;
}
void lee()
{
    int i,j,i1,j1;
    ma[startx][starty]=1;
    coada.push(make_pair(startx,starty));
    while(!coada.empty())
    {
        i=coada.front().first;
        j=coada.front().second;
        coada.pop();
        for(int directie=0; directie<4; directie++)
        {
            i1=i+di[directie];
            j1=j+dj[directie];
            if(functie(i1,j1) && ma[i1][j1]<1)
            {
                ma[i1][j1]=ma[i][j]+1;
                coada.push(make_pair(i1,j1));
            }
        }
    }
}
int main()
{
    citire();
    lee();
    out<<ma[stopx][stopy];
    return 0;
}
