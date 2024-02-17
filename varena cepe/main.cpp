#include <iostream>

using namespace std;

int v1[16], v2[16];

int main()
{
    long long a, b, a2 = 1, b2 = 1, i = 1, j, ci;
    cin >> a >> b;
    while(a != 1)
    {
        v1[i] = a%2;
        a /= 2;
        i++;
    }
    i = 1;
    while(b != 1)
    {
        v2[i] = b%2;
        b /= 2;
        i++;
    }
    j = i;
    ci = i;
    i = 1;
    while(v1[i] == v2[j] && i != ci+1 && j)
    {
        v1[i] = 2;
        v2[j] = 2;
        i++;
        j--;
    }
    i = 2;
    while(v1[i] != 2)
    {
        a2 = 2*i+v1[i];
        i++;
    }
    i = 2;
    while(v2[i] != 2)
    {
        b2 = 2*i+v1[i];
        i++;
    }
    cout << a2 + b2;
    return 0;
}
