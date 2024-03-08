#include <iostream>
#define MOD 9001

using namespace std;

int dp[100005];

int main() {
	int n, k;
	cin >> n >> k;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = i - 1; j >= i - k && j >= 1; j--) {
			dp[i] += dp[j];
			dp[i] %= MOD;
		}
	}
	cout << dp[n];
}