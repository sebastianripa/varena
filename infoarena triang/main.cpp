#include <bits/stdc++.h>

using namespace std;

ifstream fin ("triang.in");
ofstream fout ("triang.out");

pair <double, double> v[1501];

int main()
{
    int n, i, j, l, rasp = 0;
    double l1, l2, l3;
    fin >> n;
    for(i = 1; i <= n; i++)
    {
        fin >> v[i].first >> v[i].second;
        v[i].first *= 1000;
        v[i].first = (int)v[i].first;
        v[i].first /= 1000;
        v[i].second *= 1000;
        v[i].second = (int)v[i].second;
        v[i].second /= 1000;
    }
    for(i = 1; i <= n; i++)
    {
        for(j = i+1; j <= n; j++)
        {
            for(l = j+1; l <= n; l++)
            {
                l1 = sqrt((v[i].first - v[j].first)*(v[i].first - v[j].first) + (v[i].second - v[j].second)*(v[i].second - v[j].second));
                l2 = sqrt((v[l].first - v[j].first)*(v[l].first - v[j].first) + (v[l].second - v[j].second)*(v[l].second - v[j].second));
                l3 = sqrt((v[i].first - v[l].first)*(v[i].first - v[l].first) + (v[i].second - v[l].second)*(v[i].second - v[l].second));
                l1 *= 10;
                l2 *= 10;
                l3 *= 10;
                if((int)l1%10 >= 5)
                {
                    l1 = (int)l1;
                    l1++;
                }
                if((int)l2%10 >= 5)
                {
                    l2 = (int)l2;
                    l2++;
                }
                if((int)l3%10 >= 5)
                {
                    l3 = (int)l3;
                    l3++;
                }
                if(l1 == l2 && l2 == l3)
                    rasp++;
            }
        }
    }
    fout << rasp;
    return 0;
}
