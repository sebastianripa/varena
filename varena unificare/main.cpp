#include <bits/stdc++.h>

using namespace std;

ifstream fin ("unificare.in");
ofstream fout ("unificare.out");

long long v[100005], vf[10], vfm[11];

void unif2(long long a, long long b, long long c)
{
    long long ca, cb, cc, i, cd = 0;
	for(i = 1; i < 10; i++)
        vf[i] = 0;
	ca = a;
	cb = b;
	cc = c;
	while (ca)
	{
		if (vf[ca % 10] == 0)
			cd++;
		vf[ca % 10] = 1;
		ca /= 10;
	}
	while (cb)
	{
		if (vf[cb % 10] == 1)
        {
            vf[cb % 10] = 2;
            cd++;
        }
		else if(vf[cb%10] == 0)
		{
			vf[cb % 10] = 11;
			if(vf[cb % 10] > 1)
                cd++;
		}
		cb /= 10;
	}
	while (cc)
    {
        if(vf[cc%10] == 2)
        {
            vf[cc%10] = 3;
            cd++;
        }
        else if(vf[cc%10] == 11 || vf[cc%10] == 1)
        {
            vf[cc%10] = 12;
            cd++;
        }
        else if(vf[cc%10] == 0)
        {
            if(vf[cc%10] == 0)
                cd++;
            vf[cc%10] = 111;
        }
        cc /= 10;
    }
    if (vfm[10] == cd)
	{
		for (i = 9; i >= 0; i--)
		{
			if (vf[i]%10 > vfm[i])
			{
				vfm[10] = cd - 1;
				break;
			}
			else if (vf[i]%10 < vfm[i])
				break;
		}
	}
	if (vfm[10] < cd)
	{
		for (i = 9; i >= 0; i--)
		{
			if (vfm[i] >= 1)
				vfm[i] = 0;
			if (vf[i]%10 >= 1)
				vfm[i] = vf[i]%10;
		}
		vfm[10] = cd;
	}
}

void unif(long long a, long long b)
{
	long long ca, cb, i, cd = 0;
	for(i = 1; i < 10; i++)
        vf[i] = 0;
	ca = a;
	cb = b;
	while (ca)
	{
		if (vf[ca % 10] == 0)
			cd++;
		vf[ca % 10] = 1;
		ca /= 10;
	}
	while (cb)
	{
		if (vf[cb % 10] == 1)
        {
            vf[cb % 10] = 2;
            cd++;
        }
		else if(vf[cb%10] == 0)
		{
		    if(vf[cb % 10] == 0)
                cd++;
			vf[cb % 10] = 11;
		}
		cb /= 10;
	}
	if (vfm[10] == cd)
	{
		for (i = 9; i >= 0; i--)
		{
			if (vf[i]%10 > vfm[i])
			{
				vfm[10] = cd - 1;
				break;
			}
			else if (vf[i]%10 < vfm[i])
				break;
		}
	}
	if (vfm[10] < cd)
	{
		for (i = 9; i >= 0; i--)
		{
			if (vfm[i] >= 1)
				vfm[i] = 0;
			if (vf[i]%10 >= 1)
				vfm[i] = vf[i]%10;
		}
		vfm[10] = cd;
	}
}

int main()
{
	long long cer, n, k, nrc = 0, i, x, cx, xm = 0;
	fin >> cer >> n >> k;
	if (cer == 1)
	{
		for (i = 1; i <= n; i++)
		{
		    nrc = 0;
			fin >> x;
			cx = x;
			while (cx)
			{
				nrc++;
				cx /= 10;
			}
			if (nrc == k)
				xm = max(xm, x);
		}
		fout << xm;
	}
	else if (cer == 2)
	{
		for (i = 1; i <= n; i++)
			fin >> v[i];
		for (i = 2; i <= n; i++)
			unif(v[i], v[i - 1]);
		for (i = 9; i >= 0; i--)
		{
		    while (vfm[i]--)
				fout << i;
		}
	}
	else
    {
        for(i = 1; i <= n; i++)
            fin >> v[i];
        for(i = 3; i <= n; i++)
            unif2(v[i], v[i-1], v[i-2]);
        for(i = 9; i > 0; i--)
        {
            while(vfm[i]--)
                fout << i;
        }
    }
}
