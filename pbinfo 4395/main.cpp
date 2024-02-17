#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

ifstream fin ("tema.in");
ofstream fout ("tema.out");

int v[1000010];
struct
{
    int mn;
    int mx;
} ciur[1000010];

int cnt[1000010];
set<int> mp[1000010]; //mp[2] = un set de numere x care au cnt[x] = 2
pair <int, int> nums[100010];
void ciur1()
{
    int i, j;
    ciur[0].mn = -1;
    ciur[1].mn = -1;
    for(i = 2; i <= 1000000; i++)
    {
        if(ciur[i].mn == 0)
        {
            ciur[i].mx = i;
            for(j = i*2; j <= 1000000; j += i)
            {
                if(ciur[j].mn == 0)
                    ciur[j].mn = i;
                ciur[j].mx = i;
            }
        }
    }
}
int main()
{
    long long cer, n, k, st = 1, dr = 1, i, sp = 0, sc = 0, l, lm = 0;
    fin >> cer >> n >> k;
    ciur1();
    if(cer == 1)
    {
        for(i = 1; i <= n; i++)
            fin >> v[i];
        if(ciur[v[st]].mn == 0)
            sp += v[st];
        else if(ciur[v[st]].mn > 0)
            sc += v[st];
        while(dr <= n)
        {
            l = dr - st + 1;
            if(sc*sp <= k)
            {
                lm = max(l, lm);
                dr++;
                if(ciur[v[dr]].mn == 0)
                    sp += v[dr];
                else if(ciur[v[dr]].mn > 0)
                    sc += v[dr];
            }
            else
            {
                if(ciur[v[st]].mn == 0)
                    sp -= v[st];
                else if(ciur[v[st]].mn > 0)
                    sc -= v[st];
                st++;
            }
        }
        fout << lm;
    }
    else
    {
        for(i = 1; i <= n; i++)
        {
            fin >> v[i];
            if(ciur[v[i]].mn > 0)
            {
                if(ciur[v[i]].mn == ciur[v[i]].mx)
                    nums[i-1] = {ciur[v[i]].mn, 0};
                else
                    nums[i-1] = {ciur[v[i]].mn, ciur[v[i]].mx};
            }
            else if(v[i] == 1)
                nums[i-1] = {0, 0};
            else
                nums[i-1] = {v[i], 0};
        }
        nums[n] = {0, 0};
        int l = 0, r = 0;
        for(int i = 2; i <= 1000000; i ++)
            if(ciur[i].mn == 0)
                mp[0].insert(i);
        int ans = 0, ansL = 0, ansR = 0;
        while(r <= n)
        {
            do
            {
                if(nums[r].f != 0)
                {
                    mp[cnt[nums[r].f]].erase(nums[r].f);
                    cnt[nums[r].f] ++;
                    mp[cnt[nums[r].f]].insert(nums[r].f);
                }
                if(nums[r].s != 0)
                {
                    mp[cnt[nums[r].s]].erase(nums[r].s);
                    cnt[nums[r].s] ++;
                    mp[cnt[nums[r].s]].insert(nums[r].s);
                }
                r ++;
            } while(r <= n && !mp[r-l].empty());
            if(r-l-1 >= ans)
            {
                ans = r-l-1;
                ansL = l+1;
                ansR = r-1;
            }
            if(r >= n) break;
            while(l < r && mp[r-l].empty())
            {
                if(nums[l].f != 0)
                {
                    mp[cnt[nums[l].f]].erase(nums[l].f);
                    cnt[nums[l].f] --;
                    mp[cnt[nums[l].f]].insert(nums[l].f);
                }
                if(nums[l].s != 0)
                {
                    mp[cnt[nums[l].s]].erase(nums[l].s);
                    cnt[nums[l].s] --;
                    mp[cnt[nums[l].s]].insert(nums[l].s);
                }
                l ++;
            }
            if(nums[r].f == 0 && nums[r].s == 0)
                l ++, r ++;
        }
        fout << ansL << ' ' << ansR << '\n';
    }
    return 0;
}
