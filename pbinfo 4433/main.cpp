#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ifstream fin ("kth.in");
ofstream fout ("kth.out");

int v[300005], ans[300005];

Tree <pair<int, int>> st;

int main()
{
    int n, k, l, i, x, q;
    fin >> n >> k >> l;
    for(i = 1; i <= n; i++)
        fin >> v[i];
    for(i = 1; i <= l; i++)
        st.insert({v[i], i});
    ans[1] = st.find_by_order(k-1)->first;
    for(i = l+1; i <= n; i++)
    {
        st.erase({v[i-l], i-l});
        st.insert({v[i], i});
        ans[i-l+1] = st.find_by_order(k-1)->first;
    }
    fin >> q;
    while(q--)
    {
        fin >> x;
        fout << ans[x] << '\n';
    }
    return 0;
}
