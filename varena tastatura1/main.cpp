#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("tastatura1.in");
ofstream fout ("tastatura1.out");

int main()
{
    long long n = 0, r = 0;
    char c, op = '+';
    do
    {
        fin.get(c);
        if(c != '#')
        {
            if(c >= 'A' && c <= 'J')
            {
                n = n*10 + (c - 'A');
            }
            else
            {
                if(op == '+')
                {
                    r += n;
                    n = 0;
                }
                else
                {
                    r -= n;
                    n = 0;
                }
                op = c;
            }
        }
    }
    while(c != 10);
    fout << r;
    return 0;
}
