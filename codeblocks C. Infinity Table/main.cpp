#include <iostream>
#include <cmath>

using namespace std;

int row1(int n)
{
    return sqrt(n-1) + 1;
}

int main()
{
    int t, n, dr, st, row, mid, i, j;
    cin >> t;
    for(j = 1; j <= t; j++)
    {
        cin >> n;
        row = row1(n);
        st = (row-1)*(row-1) + 1;
        dr = row*row;
        mid = (dr+st)/2;
        if(n == mid)
            cout << row << ' ' << row << '\n';
        else if(n < mid)
            cout << row - (mid - n) << ' ' << row << '\n';
        else
            cout << row << ' ' << row - (n - mid) << '\n';
    }
    return 0;
}
