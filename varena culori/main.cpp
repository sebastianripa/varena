#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("culori.in");
ofstream fout ("culori.out");

int main()
{
    int n, vf[99] = {0}, i, x;
    bool afisat = false;
    fin >> n;
    for(i = 0; i < n; i++)
    {
        fin >> x;
        vf[x-1]++;
    }
    for(i = 0; i < 99; i++)
    {
        while(vf[i] > 0)
        {
            if(afisat)
            {
                fout << " ";
            }
            fout << i+1;
            vf[i]--;
            afisat = true;
        }
    }
    return 0;
}
