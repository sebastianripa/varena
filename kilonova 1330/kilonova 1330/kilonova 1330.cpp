#include <fstream>
#include <map>

using namespace std;

ifstream cin("cern.in");
ofstream cout("cern.out");

map <pair<int, int>, int> mp;

void univ(int pi, int t, int c, int s) {
    int gr = 0;
    while (t > gr) {
        if (gr) {
            if (pi == 1) {
                if (c == 1)
                    c = 3, pi = 3;
                else
                    c = 3, pi = 2;
                s = -s;
            }
            else if (pi == 2) {
                if (c == 2)
                    c = 1, pi = 1;
                else
                    c = 1, pi = 3;
                s = -s;
            }
            else {
                if (c == 3)
                    c = 2, pi = 2;
                else
                    c = 2, pi = 1;
                s = -s;
            }
        }
        t -= gr;
        if (pi == 1) {
            if (c == 1) {
                if (s == 1)
                    gr = 60;
                else
                    gr = 300;
            }
            else {
                if (s == 1)
                    gr = 300;
                else
                    gr = 60;
            }
        }
        else if (pi == 2) {
            if (c == 2) {
                if (s == 1)
                    gr = 60;
                else
                    gr = 300;
            }
            else {
                if (s == 1)
                    gr = 300;
                else
                    gr = 60;
            }
        }
        else {
            if (c == 3) {
                if (s == 1)
                    gr = 60;
                else
                    gr = 300;
            }
            else {
                if (s == 1)
                    gr = 300;
                else
                    gr = 60;
            }
        }
    }
    int g = mp[{c, pi}] + t * s;
    if (g < 0)
        g += 360;
    if (g > 360)
        g -= 360;
    cout << g << ' ' << c;
    exit(0);
}

int main()
{
    char c;
    cin >> c;
    long long s, t;
    cin >> s >> t;
    t %= 1080;
    mp[{1, 1}] = 180;
    mp[{1, 3}] = 240;
    mp[{2, 1}] = 0;
    mp[{2, 2}] = 300;
    mp[{3, 3}] = 60;
    mp[{3, 2}] = 120;
    if (c == 'A') {
        if (s == 1) {
            if (t < 180)
                cout << t << " 1", exit(0);
            t -= 180;
            univ(1, t, 2, -1);
        }
        else {
            if (t < 120)
                cout << 360 - t << " 1", exit(0);
            t -= 120;
            univ(3, t, 3, 1);
        }
    }
    if (c == 'B') {
        if (s == 1) {
            if (t < 120)
                cout << 60 + t << " 1", exit(0);
            t -= 120;
            univ(1, t, 2, -1);
        }
        else {
            if (t < 180) {
                t = 60 - t;
                if (t < 0)
                    t += 360;
                cout << t << " 1", exit(0);
            }
            t -= 180;
            univ(3, t, 3, 1);
        }
    }
    if (c == 'C') {
        if (s == 1) {
            if (t < 180)
                cout << 120 + t << " 2", exit(0);
            t -= 180;
            univ(2, t, 3, -1);
        }
        else {
            if (t < 120)
                cout << 120 - t << " 2", exit(0);
            t -= 120;
            univ(1, t, 1, 1);
        }
    }
    if (c == 'D') {
        if (s == 1) {
            if (t < 120)
                cout << 180 + t << " 2", exit(0);
            t -= 120;
            univ(2, t, 3, -1);
        }
        else {
            if (t < 180)
                cout << 180 - t << " 2", exit(0);
            t -= 180;
            univ(1, t, 1, 1);
        }
    }
    if (c == 'E') {
        if (s == 1) {
            if (t < 180) {
                t += 240;
                if (t >= 360)
                    t -= 360;
                cout << t << " 3", exit(0);
            }
            t -= 180;
            univ(3, t, 1, -1);
        }
        else {
            if (t < 120) {
                t += 120;
                cout << 360 - t << " 3", exit(0);
            }
            t -= 120;
            univ(2, t, 2, 1);
        }
    }
    if (c == 'F') {
        if (s == 1) {
            if (t < 120) {
                t += 300;
                if (t >= 360)
                    t -= 360;
                cout << t << " 3", exit(0);
            }
            t -= 120;
            univ(3, t, 1, -1);
        }
        else {
            if (t < 180) {
                t += 60;
                cout << 360 - t << " 3", exit(0);
            }
            t -= 180;
            univ(2, t, 2, 1);
        }
    }
    return 0;
}