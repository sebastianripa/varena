#include <iostream>

using namespace std;

int main()
{
    int nrc = 0, i, ci, c = 0;
    for(i = 1; i <= 2018; i++)
    {
        ci = i;
        while(ci)
        {
            nrc++;
            if(nrc == 299)
            {
                c = ci%10;
                break;
            }
            ci /= 10;
        }
        if(c != 0)
            break;
    }
    cout << c;
    return 0;
}
