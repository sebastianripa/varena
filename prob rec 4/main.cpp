#include <iostream>

using namespace std;

string s;

bool pal(int in, int sf)
{
    if(in >= sf)
        return true;
    if(s[in] == s[sf])
        pal(in+1, sf-1);
    else
        return false;
}

int main()
{
    int in, sf;
    cin >> s;
    in = 0;
    sf = s.length() - 1;
    cout << pal(in, sf);
    return 0;
}
