#include <bits/stdc++.h>

using namespace std;
ifstream fin("interclasare1.in");
ofstream fout("interclasare1.out");
long long  n,m,x,i,v1[100005],v2[100005],v[200005],f1,f2,f=1;
int main()
{
    fin>>n;
    for(i = 1; i <= n; i++)
        fin>>v1[i];
    fin>>m;
    for(i=1;i<=m;i++)
        fin>>v2[i];
    f1=1;
    f2=1;
    f=1;
    while(f1<=n && f2<=m){
        if(v1[f1] < v2[f2]){
            v[f] = v1[f1];
            f++;
            f1++;
        }
        else if (v2[f2] < v1[f1]){
            v[f] = v2[f2];
            f++;
            f2++;
        }
        else{
            v[f] = v1[f1];
            f1++;
            f2++;
            f++;
        }
    }
    while(f1 <= n){
        v[f]=v1[f1];
        f1++; f++;
    }
    while(f2 <= m){
        v[f]=v2[f2];
        f2++; f++;
    }
    for(i = 1; i < f; i++){
        fout<<v[i]<<" ";
        if(i%10==0)
            fout<<'\n';

    }
    return 0;
}
