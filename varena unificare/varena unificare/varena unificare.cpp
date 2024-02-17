#include <iostream>

using namespace std;

int v[100005], vf[10], vfm[11];

void unif(int a, int b)
{
	int nrcd1 = 0, nrcd2 = 0, ca, cb, i, cd = 0;
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
		if (vf[cb % 10])
			vf[cb % 10] = 2;
		else
		{
			vf[cb % 10] = 1;
			cd++;
		}
	}
	if (vfm[10] == cd)
	{
		for (i = 9; i >= 0; i--)
		{
			if (vf[i] > vfm[i])
			{
				vfm[10] = cd - 1;
				break;
			}
			else if (vf[i] < vfm[i])
				break;
		}
	}
	if (vfm[10] < cd)
	{
		for (i = 9; i >= 0; i++)
		{
			if (vfm[i] >= 1)
				vfm[i] = 0;
			if (vf[i] >= 1)
				vfm[i] = vf[i];
		}
	}
	return;
}

int main()
{
	long long cer, n, k, nrc = 0, i, x, cx, xm = 0, m, mm = 0;
	cin >> cer >> n >> k;
	if (cer == 1)
	{
		for (i = 1; i <= n; i++)
		{
			cin >> x;
			cx = x;
			while (cx)
			{
				nrc++;
				cx /= 10;
			}
			if (nrc == 0)
				xm = max(xm, x);
		}
		cout << xm;
	}
	else if (cer == 2)
	{
		for (i = 1; i <= n; i++)
			cin >> v[i];
		for (i = 2; i <= n; i++)
			unif(v[i], v[i - 1]);
		for (i = 9; i >= 0; i--)
		{
			while (vfm[i]--)
				cout << i;
		}
	}
}
