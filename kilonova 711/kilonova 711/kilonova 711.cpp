#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

ifstream cin("text.in");
ofstream cout("text.out");

char ch[1005];
vector<string>v;

int main()
{
    int nmax, i, last = 0, cnt = 0, spatii = 0, j, k, rest = 0, ok = 1;
    string s;
    cin >> nmax;
    while (cin.getline(ch, 1000)) {
        s = "";
        v.clear();
        for (i = 0; i < strlen(ch); i++) {
            if (ch[i] != ' ')
                s += ch[i];
            else if (s != "")
                v.push_back(s), s = "";
        }
        if (s != "")
            v.push_back(s);
        last = 0;
        cnt = 0; ok = 0; last = 0;
        for (i = 0; i < v.size(); i++) {
            cnt += v[i].size();
            if (cnt > nmax) {
                if (i - 1 == last) {
                    cout << v[j] << '\n';
                    cnt = 0;
                    continue;
                }
                cnt -= v[i].size();
                cnt--;
                int nrs = (i - 1) - last;
                spatii = (nmax - cnt) / nrs;
                rest = (nmax - cnt) % nrs;
                for (j = last; j < i; j++) {
                    cout << v[j];
                    ok = 1;
                    if (j < i - 1) {
                        for (k = 1; k <= spatii; k++)
                            cout << " ";
                        if (rest > 0)
                            rest--, cout << " ";
                        cout << " ";
                    }
                }
                cnt = v[i].size() + 1;
                last = i;
                if (ok == 1)
                    cout << '\n';
            }
            else
                cnt++;
        }
        for (j = last; j < v.size(); j++)
            cout << v[j] << " ";
        cout << '\n';
    }
    return 0;
}