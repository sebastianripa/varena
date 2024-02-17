#include <iostream>

using namespace std;

char v[51];
bool ok[5];

int main()
{
	int t, n, i;
	cin >> t;
	while (t--)
	{
		for (i = 1; i <= 4; i++)
			ok[i] = 0;
		cin >> n;
		cin >> v;
		for (i = 0; i <= n-1; i++)
		{
			if ((v[i] == 'm' || v[i] == 'M') && ok[4] == 0 && ok[2] == 0 && ok[3] == 0)
				ok[1] = 1;
			else if ((v[i] == 'e' || v[i] == 'E') && ok[1] == 1 && ok[3] == 0 && ok[4] == 0)
				ok[2] = 1;
			else if ((v[i] == 'o' || v[i] == 'O') && ok[1] == 1 && ok[2] == 1 && ok[4] == 0)
				ok[3] = 1;
			else if ((v[i] == 'w' || v[i] == 'W') && ok[1] == 1 && ok[2] == 1 && ok[3] == 1)
				ok[4] = 1;
			else
				break;
		}
		if (i == n && ok[1] == 1 && ok[2] == 1 && ok[3] == 1 && ok[4] == 1)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
}