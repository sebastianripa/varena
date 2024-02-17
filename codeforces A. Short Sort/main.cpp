#include <iostream>

using namespace std;

string s;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        cin >> s;
        if(s == "abc" || s == "bac" || s == "cba" || s == "acb")
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}
