#include <iostream>
#include <string>

using namespace std;

char s[100];

int main()
{
    int t, nra = 0, nrb = 0, nrc = 0, i, j;
    char c;
    cin >> t;
    for(i = 1; i <= t; i++)
    {
        nra = 0;
        nrb = 0;
        nrc = 0;
        cin >> s;
        for(j = 0; j <= strlen(s)-1; j++)
        {
            if(s[j] == 'A')
                nra++;
            else if(s[j] == 'B')
                nrb++;
            else
                nrc++;
        }
        if(nra+nrc == nrb)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}
