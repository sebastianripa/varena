#include <iostream>
#include <vector>

using namespace std;

vector <int> coins;
int vmc[10005];

int main() {
    int n;
    cin >> n;
    int amount;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        coins.push_back(x);
    }
    cin >> amount;
    for(int i = 1; i <= amount; i++)
    if (!amount)
        cout << 0, exit(0);
    for (auto x : coins) {
        for (int i = x; i <= amount; i++) {
            if (vmc[i] == 0)
                vmc[i] = 21e8;
            vmc[i] = min(vmc[i], vmc[i - x] + 1);
        }
    }
    if (vmc[amount] == 0)
        cout << -1, exit(0);
    cout << vmc[amount];
}