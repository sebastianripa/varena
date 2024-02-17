#include <iostream>
#include <fstream>

using namespace std;


ifstream fin ("kdiv.in");
ofstream fout ("kdiv.out");

int v[170];
int idx = 1;
void calculatePrimes(int n)
{
    bool prime = true;
    for(int i = 0; i < idx; i ++)
    {
        if(v[i] * v[i] > n) break;
        if(n % v[i] == 0)
        {
            prime = false;
            break;
        }
    }
    if(prime)
    {
        v[idx] = n;
        idx ++;
    }
}
int findPF(int a)
{
    int ans = 0;
    int i;
    for(i = 0; v[i] * v[i] <= a; i ++)
    {
        if(a % v[i] == 0) ans ++;
        while(a % v[i] == 0) a /= v[i];
        if(a == 1) break;
    }
    if(a != 1) ans ++;
    return ans;
}
int main()
{
    v[0] = 2;
    long long x, n, nrcdp = 0, i, nrdp = 0, k;
    fin >> n >> k;
    if(k > 7)
    {
        fout << "0";
        return 0;
    }
    for(i = 3; i <= 1010; i ++)
        calculatePrimes(i);
    for(i = 0; i < n; i++)
    {
        fin >> x;
        nrdp = findPF(x);
        if(x <= 1) nrdp = 0;
        if(nrdp == k) nrcdp ++;
    }
    fout << nrcdp << "\n";
    return 0;
}
