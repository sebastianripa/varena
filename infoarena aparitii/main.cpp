#include <iostream>
#include <map>
#include <fstream>
#define cin fin
#define cout fout

using namespace std;

ifstream fin ("aparitii.in");
ofstream fout ("aparitii.out");

int m[10][9];

int main()
{
    int n, k, y;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> y;
        mp[y]++;
    }
    for(auto x : mp) {
        if(x.second%k != 0) {
            cout << x.first;
            break;
        }
    }
    return 0;
}
