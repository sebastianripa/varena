#include <bits/stdc++.h>
#define cin fin
#define cout fout

using namespace std;

ifstream fin ("piramida.in");
ofstream fout ("piramida.out");

int v[100];

int main()
{
    int n, l, i, s, maxi = 0, cs, j = 1, cj, l1, ccj;
    cin >> n >> l;
    s = n*l;
    for(i = 2; i <= l-1; i += 2)
    {
        cout << s << s;
        cs = s;
        cj = j;
        while(cs)
        {
            v[j++] = cs%10;
            cs /= 10;
        }
        swap(v[cj], v[j-1]);
        ccj = j-1;
        for(l1 = cj; l1 <= ccj; l1++)
            v[j++] = v[l1];
        s += l - i;
    }
    cout << s << '\n';
    cj = j;
    while(s)
    {
        v[j++] = s%10;
        s /= 10;
    }
    swap(v[cj], v[j-1]);
    j--;
    for(i = 2; i <= j; i++)
    {
        s = 0;
        s = v[i-1]*10 + v[i];
        maxi = max(maxi, s);
    }
    cout << maxi;
    return 0;
}
