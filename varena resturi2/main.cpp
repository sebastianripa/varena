#include <iostream>

using namespace std;

int main()
{
    int t, s, k, i, j, sr = 0;
    cin >> t;
    for(j = 1; j <= t; j++)
    {
        cin >> s >> k;
        i = 1;
        while(sr < s)
        {
            sr += i%k;
            i++;
        }
        if(sr == s)
            cout << i - 1 << '\n';
        else
            cout << "kuku" << '\n';
    }
    return 0;
}
