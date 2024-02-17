#include <iostream>

using namespace std;

int main()
{
    int t, indf = 0, ind1, ind2, i, j, pn;
    char l1, l2;
    cin >> t;
    for(i = 1; i <= t; i++)
    {
        cin.get();
        cin.get(l1);
        cin.get(l2);
        ind1 = l1 - 96;
        ind2 = l2 - 96;
        pn = 25*(ind1 - 1) + 1;
        if(ind1 > ind2)
            indf = pn + ind2 - 1;
        else
            indf = pn + ind2 - 2;
        cout << indf << '\n';
    }
    return 0;
}
