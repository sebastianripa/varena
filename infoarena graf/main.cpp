#include <iostream>

using namespace std;

int q1 = 1, q2, fn;
map <int, vector<int>> adj;
queue <int> nxt;
int vf1[7501], vf2[7501];

class graf {
public:
    void addEdge(int n1, int n2) {
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
    void dfs(int st);
};

void graf::dfs(int st) {
    q1--;
    nxt.pop();
    for(auto x : adj[st]) {

    }
}

int main()
{

    return 0;
}
