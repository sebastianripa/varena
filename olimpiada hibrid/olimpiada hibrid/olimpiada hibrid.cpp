#include <iostream>

using namespace std;

int m[1000][1000];

int main()
{
	int n, r, k, i, j, p1, p2, d, nr;
	char c;
	cin >> n >> r >> k;
	for (i = 1; i <= r; i++)
	{
		cin >> p1 >> p2 >> d;
		m[p1][p2] = d;
	}
	while (k--)
	{
		cin >> c;
		cin >> nr;
		if (c == 'A')
		{
			nr %= n;
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					if (m[i][j] != 0)
					{
						if (m[i][j] == 1)
						{
							if (i - nr < 0)
							{
								m[n - nr + i][j] = m[i][j];
								m[i][j] = 0;
							}
							else
							{
								m[i - nr][j] = m[i][j];
								m[i][j] = 0;
							}
						}
						else if (m[i][j] == 2)
						{
							if (j + nr >= n)
							{
								m[i][nr - n + j] = m[i][j];
								m[i][j] = 0;
							}
							else
							{
								m[i][j + nr] = m[i][j];
								m[i][j] = 0;
							}
						}
						else if (m[i][j] == 3)
						{
							if (i + nr >= n)
							{
								m[nr - n + i][j] = m[i][j];
								m[i][j] = 0;
							}
							else
							{
								m[i + nr][j] = m[i][j];
								m[i][j] = 0;
							}
						}
						else
						{
							if (i - nr < 0)
							{
								m[i][n - nr + j] = m[i][j];
								m[i][j] = 0;
							}
							else
							{
								m[i][j - nr] = m[i][j];
								m[i][j] = 0;
							}
						}
					}
				}
			}
		}
		else if (c == 'R')
		{
			nr %= 4;
			for(i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					if (m[i][j] != 0)
					{
						m[i][j] += nr;
						m[i][j] %= 4;
					}
				}
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (m[i][j] != 0)
				cout << i << ' ' << j << '\n';
		}
	}
}
