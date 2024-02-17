#include <bits/stdc++.h>
//#define fin cin
//#define fout cout

using namespace std;

ifstream fin ("jack.in");
ofstream fout ("jack.out");

int main()
{
    long long n, i = 1, s = 0, d, ans;
    fin >> n;
    n = abs(n);
    while(s < n)
    {
        s += i;
        i++;
    }
    i--;
    if(s%2 == n%2)
        fout << i;
    else if((s+i+1)%2 == n%2)
        fout << i+1;
    else
        fout << i+2;
    return 0;
}
