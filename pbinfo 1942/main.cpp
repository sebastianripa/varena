#include <iostream>

using namespace std;

int z[1010], x[1010], y[1010];

void produs()
{
    int i, j, t = 0;
    z[0] = x[0] + y[0] - 1;
    for(i = 1; i <= x[0]+y[0]; i++)
        z[i] = 0;
    for(i = 1; i <= x[0]; i++) {
        for(j = 1; j <= y[0]; j++)
            z[j+i-1] += x[i]*y[j];
    }
    for(i = 1; i <= z[0]; i++) {
        t += z[i];
        z[i] = t%10;
        t /= 10;
    }
    while(t != 0){
        z[0]++;
        z[z[0]] = t%10;
        t /= 10;
    }
    for(i=0; i<=z[0]; i++)
        x[i]=z[i];
}

void schimbMic(int n) {
    y[0] = 0;
    for(; n; n /= 10) {
        y[y[0]] = n%10;
        y[0]++;
    }
}

void schimbMare() {
    x[0] = z[0];
    for(int i = 1; i <= z[0]; i++) {
        x[i] = z[i];
        z[i] = 0;
    }
    z[0] = 0;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n-1; i++) {
        schimbMic(i);
        produs();
        schimbMare();
    }
    for(int i = 1; i <= x[0]; i++)
        cout << x[i];
    return 0;
}
