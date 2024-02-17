#include <iostream>

using namespace std;

int v[200005];

int main()
{
    int t, ls = 1;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(ls < 3) {
            v[1] = 2;
            v[2] = 3;
            ls = 3;
        }
        for(; ls <= n; ls++) {
            v[ls] = v[ls-1] + 1;
            if((v[ls] + v[ls-1])%3 == 0)
                v[ls]++;
            if(3*v[ls]%(v[ls-1]+v[ls-2])  == 0)
                v[ls]++;
        }
        for(int i = 1; i <= n; i++)
            cout << v[i] << ' ';
        cout << '\n';
    }
    return 0;
}
