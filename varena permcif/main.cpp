#include <fstream>

using namespace std;

ifstream cin ("permcif.in");
ofstream cout ("permcif.out");

int main()
{
    int t = 5;
    while(t--) {
        string a, b;
        cin >> a >> b;
        while(a.size() < b.size())
            a += '0';
        while(a.size() > b.size())
            b += '0';
        int offset = 0, i;
        for(i = 0; i < b.size(); i++) {
            if(a[0] == b[i]) {
                offset = i;
                int j;
                for(j = 0; j < a.size(); j++, offset++) {
                    if(offset == b.size())
                        offset = 0;
                    if(a[j] != b[offset])
                        break;
                }
                if(j == a.size())
                    break;
            }
        }
        if(i != b.size())
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
    return 0;
}
