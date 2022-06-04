#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree <int,  null_type,  less<int>,  rb_tree_tag,  tree_order_statistics_node_update>

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, c;
  cin >> n;
  ordered_set s;
  for(int i = 0; i < n; ++i) {
    cin >> c;
    s.insert(c);
    int smaller = s.order_of_key(c);
    cout << i + 1 - smaller << '\n';
  }
}
