#include <iostream>

using namespace std;

int main()
{
    int n, k = 0;
    cin >> n;
    for(int i = 2; i <= n; i++)
    {
        int a = i;
        while(a%5 == 0)
            {k++; a/=5;}
    }
    cout << k;
    return 0;
}
