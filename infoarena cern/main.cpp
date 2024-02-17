#include <iostream>

using namespace std;

int c;

int A(int s, int t)
{
    int g = 0, i = 1;
    c = 1;
    if(s == 1)
    {
        t %= 1080;
        if(i%7 + 1 == 2)
        {
            if(t >= 180)
            {
                t -= 180;
                g = 0;
                c = 2;
                i++;
            }
            else
                return g + t;
        }
        if(i%7 + 1 == 3)
        {
            if(t >= 60)
            {
                t -= 60;
                g = 120;
                c = 3;
                i++;
            }
            else
                return g + t;
        }
        if(i%7 + 1 == 4)
        {
            if(t >= 300)
            {
                t -= 300;
                g = 240;
                c = 1;
                i++;
            }
            else
                return g + t;
        }
        if(i%7 + 1 == 5)
        {
            if(t >= 60)
            {
                t -= 60;
                g = 0;
                c = 2;
                i++;
            }
            else
                return g + t;
        }
        if(i%7 + 1 == 6)
        {
            if(t >= 300)
            {
                t -= 300;
                g = 120;
                c = 3;
                i++;
            }
            else
                return g + t;
        }
        if(i%7 + 1 == 7)
        {
            if(t >= 60)
            {
                t -= 60;
                g = 240;
                c = 1;
                i++;
            }
            else
                return g + t;
        }
        if(i%7 + 1 == 1)
        {
            if(t >= 120)
            {
                t -= 120;
                g = 0;
                c = 1;
                i++;
            }
            else
                return g + t;
        }
    }
    else
    {
        t %= 1420;
        if(i%7 + 1 == 2)
        {
            if(t >= 180)
            {
                t -= 180;
                g = 0;
                c = 2;
                i++;
            }
            else
                return g + t;
        }
        if(i%7 + 1 == 3)
        {
            if(t >= 300)
            {
                t -= 300;
                g = 120;
                c = 3;
                i++;
            }
            else
                return g + t;
        }
        if(i%7 + 1 == 4)
        {
            if(t >= 60)
            {
                t -= 60;
                g = 240;
                c = 1;
                i++;
            }
            else
                return g + t;
        }
        if(i%7 + 1 == 5)
        {
            if(t >= 300)
            {
                t -= 300;
                g = 0;
                c = 2;
                i++;
            }
            else
                return g + t;
        }
        else if(i%7 + 1 == 6)
        {
            if(t >= 60)
            {
                t -= 60;
                g = 120;
                c = 3;
                i++;
            }
            else
                return g + t;
        }
        if(i%7 + 1 == 7)
        {
            if(t >= 300)
            {
                t -= 300;
                g = 240;
                c = 1;
                i++;
            }
            else
                return g + t;
        }
        if(i%7 + 1 == 1)
        {
            if(t >= 240)
            {
                t -= 240;
                g = 0;
                c = 1;
                i++;
            }
            else
                return g + t;
        }
    }
}

int B(int s, int t)
{
    int g = 0, i = 1;
    c = 1;
    t %= 1260;
    if(s == 1)
    {
        if(i%7 + 1 == 2)
        {
            if(t >= 120)
            {
                t -= 120;
                g = 0;
                c = 2;
                i++;
            }
            else
                return g + t;
        }
        if(i%7 + 1 == 3)
        {
            if(t >= 60)
            {
                t -= 60;
                g = 120;
                c = 3;
                i++;
            }
            else
                return g + t;
        }
        if(i%7 + 1 == 4)
        {
            if(t >= 300)
            {
                t -= 300;
                g = 240;
                c = 1;
                i++;
            }
            else
                return g + t;
        }
        if(i%7 + 1 == 5)
        {
            if(t >= 60)
            {
                t -= 60;
                g = 0;
                c = 2;
                i++;
            }
            else
                return g + t;
        }
        if(i%7 + 1 == 6)
        {
            if(t >= 300)
            {
                t -= 300;
                g = 120;
                c = 3;
                i++;
            }
            else
                return g + t;
        }
        if(i%7 + 1 == 7)
        {
            if(t >= 60)
            {
                t -= 60;
                g = 240;
                c = 1;
                i++;
            }
            else
                return g + t;
        }
        if(i%7 + 1 == 1)
        {
            if(t >= 180)
            {
                t -= 180;
                g = 0;
                c = 1;
                i++;
            }
            else
                return g + t;
        }
    }
    else
    {
        if(i%7 + 1 == 2)
        {
            if(t >= 180)
            {
                t -= 180;
                g = 0;
                c = 2;
                i++;
            }
            else
                return g + t;
        }
        if(i%7 + 1 == 3)
        {
            if(t >= 60)
            {
                t -= 60;
                g = 120;
                c = 3;
                i++;
            }
            else
                return g + t;
        }
        if(i%7 + 1 == 4)
        {
            if(t >= 60)
            {
                t -= 60;
                g = 240;
                c = 1;
                i++;
            }
            else
                return g + t;
        }
        if(i%7 + 1 == 5)
        {
            if(t >= 300)
            {
                t -= 300;
                g = 0;
                c = 2;
                i++;
            }
            else
                return g + t;
        }
        else if(i%7 + 1 == 6)
        {
            if(t >= 60)
            {
                t -= 60;
                g = 120;
                c = 3;
                i++;
            }
            else
                return g + t;
        }
        if(i%7 + 1 == 7)
        {
            if(t >= 300)
            {
                t -= 300;
                g = 240;
                c = 1;
                i++;
            }
            else
                return g + t;
        }
        if(i%7 + 1 == 1)
        {
            if(t >= 240)
            {
                t -= 240;
                g = 0;
                c = 1;
                i++;
            }
            else
                return g + t;
        }
    }
}

int main()
{
    int s, t, g;
    char p;
    cin.get(p);
    cin >> s >> t;
    if(p == 'A')
        cout << A(s, t) << ' ' << c;
    else if(p == 'B')
        cout << B(s, t) << ' ' << c;
    return 0;
}

/*
#include <fstream>

using namespace std;

ifstream fin ("cern.in");
ofstream fout ("cern.out");

int c, grade[10] = { 0, 60, 720, 780, 360, 420 };

int main()
{
    int s, t, g;
    char p;
    fin.get(p);
    fin >> s >> t;
    t %= 1080;
    t = ( 10800 + s * t + grade[p - 'A'] ) % 1080;
    if(t < 180)
    {
        g = t;
        c = 1;
    }
    else if(t < 240)
    {
        g = 540 - t;
        c = 2;
    }
    else if(t < 540)
    {
        g = t - 120;
        c = 3;
    }
    else if(t < 600)
    {
        g = 780 - t;
        c = 1;
    }
    else if(t < 900)
    {
        g = t - 600;
        c = 2;
    }
    else if(t < 960)
    {
        g = 1020 - t;
        c = 3;
    }
    else
    {
        g = t - 720;
        c = 1;
    }
    g %= 360;
    fout << g << ' ' << c;
    return 0;
}

*/
