#include <bits/stdc++.h>

using namespace std;
int n, k, d;
pair < int, int > v[500001];
bool verif ( int timp )
{
	int maxim = 0;
	for ( int i = 1; i <= n; i++ )
	{
		if ( v[i].second <= timp and maxim + k >= v[i].first )
			maxim = v[i].first ;
	}
	if ( maxim + k >= d )
		return true;
	return false;

}
int caut_bin()
{
	int ans = -1, pas = 1 << 30;
	while ( pas )
	{
		if ( verif(ans + pas) == false )
			ans += pas;
		pas /= 2;
	}
	if ( ans == INT_MAX - 1 )
		return -1;
	return ans + 1;
}

int main()
{
	ifstream cin ( "broasca2.in" );
	ofstream cout ( "broasca2.out" );
	cin >> d >> k >> n;
	for ( int i = 1; i <= n; i++ )
	{
		cin >> v[i].second>> v[i].first;
	}
	sort(v + 1, v + n + 1);
	cout << caut_bin();
	return 0;
}
