#include <iostream>

using namespace std;

char v1[100001], v2[100001];
int vf[123];
pair <char, char> v;

int main()
{
    int cod, i = 1, j;
    while(cin.get(v1[i]) && v1[i] != '\n')
    {
        i++;
    }
    i = 1;
    while(cin.get(v2[i]) && v2[i] != '\n')
    {
        if(v1[i] != v2[i] )
        i++;
    }
    return 0;
}
