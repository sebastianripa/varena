#include <iostream>

using namespace std;

int main()
{
    bool vdi = false;
    char c;
    while(c != '\n')
    {
        cin.get(c);
        if(c == 'a' || c == 'e' || c == 'o' || c == 'u')
            vdi = true;
    }
    if(vdi)
        cout << "NU";
    else
        cout << "DA";
    return 0;
}
