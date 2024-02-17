#include <bits/stdc++.h>

using namespace std;

char v[25], c[2005];

bool verifVocala(char c)
{
    if(c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'I' || c == 'i' || c == 'O' || c == 'o' || c == 'U' || c == 'u')
        return true;
    else
        return false;
}

int main()
{
    int n = 1, i;
    while(cin.getline(c, 2000))
        cout << c[n++];
    return 0;
}
