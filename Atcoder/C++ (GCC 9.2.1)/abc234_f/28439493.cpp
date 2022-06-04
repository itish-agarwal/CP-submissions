#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree <int,  null_type,  less<int>,  rb_tree_tag,  tree_order_statistics_node_update>

/* 
less<int> -> acts as set
less_equal<int> -> acts as multiset

order_of_key (k) : Number of items strictly smaller than k .
find_by_order(k) : K-th element in a set (counting from zero).
*/

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n, k;
   cin >> n >> k;
   --k;
   vector<int> p(n);
   for (int i = 0; i < n; ++i) {
      cin >> p[i];
   }
   ordered_set s;
   for (int i = 0; i < k; ++i) {
      s.insert(p[i]);
   }
   int el = k;
   for (int i = k; i < n; ++i) {
      s.insert(p[i]);
      el++;
      cout << *s.find_by_order(el - k - 1) << '\n';
   }
}