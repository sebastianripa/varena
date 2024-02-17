#include <fstream>
#define MOD 999983
#define int long long

using namespace std;

ifstream cin("tango.in");
ofstream cout("tango.out");

int dp[13], vf[15];

int put(int n, int p)
{
	int ans = 1;
	for (int i = p; i; i >>= 1)
	{
		if (i % 2)
			ans = ans * n;
		n = n * n;
		n %= MOD;
		ans %= MOD;
	}
	return ans;
}


signed main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		vf[x]++;
	}
	dp[0] = 1;
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= i; j++)
			dp[i] += vf[j] * dp[i - j];
		dp[i] %= MOD;
	}
	cout << put(dp[8], k/8);
}