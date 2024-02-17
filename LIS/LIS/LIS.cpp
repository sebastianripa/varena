#include <iostream>
#include <vector>

using namespace std;

vector <int> nums;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		nums.push_back(x);
	}
	int lis[2505], ans = 0;
	for (int i = 0; i < nums.size(); i++) {
		for (int j = 0; j < i; j++)
			if (nums[i] > nums[j])
				lis[i] = max(lis[i], lis[j] + 1);
		ans = max(ans, lis[i]);
	}
	return ans + 1;
}