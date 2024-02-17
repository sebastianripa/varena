#include <iostream>

using namespace std;

int palindMicAdv(int n) {
    int cn = n, ogl = 0;
    while(cn) {
        ogl *= 10 + cn%10;
        cn /= 10;
    }

}

int main()
{
    int n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        int cx = x;
        int nrc = 0, p = 1;
        while(cx) {
            cx /= 10;
            nrc++;
            if(nrc%2 == 1)
                p *= 10;
        }
        int pma = palindMicAdv(x);
        if(nrc)
    }
    return 0;
}
