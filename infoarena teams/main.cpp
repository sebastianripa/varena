#include <fstream>

using namespace std;

ifstream fin ("teams.in");
ofstream fout ("teams.out");

int v[100005];

void QuickSort(int v[], int st, int dr)
{
	if(st<dr)
	{
		int m=(st+dr)/2;
		int aux=v[st];
		v[st]=v[m];
		v[m]=aux;
		int i=st,j=dr,d=0;
		while(i<j)
		{
			if(v[i]>v[j])
			{
				aux=v[i];
				v[i]=v[j];
				v[j]=aux;
				d=1-d;
			}
			i =d;
			j-=1-d;
		}
		QuickSort(v,st,i-1);
		QuickSort(v,i+1,dr);
	}
}

int main()
{
    int n, a, b, i, j, in, sf, ans = 0;
    fin >> n >> a >> b;
    for(i = 1; i <= n; i++)
        fin >> v[i];
    for(i = 1; i <= n; i++)
    {
        in = a - v[i];
        sf = b - v[i];
        for(j = i + 1; j <= n; j++)
        {
            if(v[j] >= in && v[j] <= sf)
                ans++;
        }
    }
    fout << ans;
    return 0;
}
