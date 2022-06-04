#include <bits/stdc++.h>
 
using namespace std;
 
#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << ": "; pr(x); cout << "]\n";
#else
#define debug(x...)
#endif
 
void pr(string x)  { cout << '\"' << x << '\"'; }
void pr(long long x)  { cout << x; }
void pr(bool x)  { cout << x; }
void pr(int x)  { cout << x; }
 
template <class T, class V> void pr(const map<T, V>& mp);
template <class T, class... V> void pr(T t, V... v);
template <class T> void pr(const multiset<T>& pq);
template <class T> void pr(const vector<T>& v);
 
template <class T, class V> void pr(const map<T, V>& mp) {
   for (auto it = mp.begin(); it != mp.end(); ++it) { pr(*it); cout << " "; }
}
template <class T> void pr(const multiset<T>& pq) {
   vector<T> values(pq.begin(), pq.end()); pr(values);
}
template <class T> void pr(const vector<T>& v) {
   for (int i = 0; i < (int) v.size(); ++i) { pr(v[i]); cout << (i + 1 < (int) v.size() ? " " : ""); }
}
template <class T, class... V> void pr(T t, V... v) {
   pr(t); if(sizeof...(v)) cout << " | "; pr(v...);
}
//Global space begins
 
vector<int> topological_sort(const vector<vector<int>>& edges) {
   int n = edges.size();
   vector<int> in_degree(n);
   vector<int> order;
 
   for(int i = 0; i < n; ++i) 
      for(int lead : edges[i]) 
         in_degree[lead]++;
 
   for(int i = 0; i < n; ++i) 
      if(in_degree[i] == 0) 
         order.push_back(i);
 
   int cur = 0;
 
   while(cur < (int) order.size()) {
      int a = order[cur++];
 
      for(int b : edges[a])
         if(--in_degree[b] == 0)
            order.push_back(b);
   }
 
   return order;
}
 
void test_case() {
   int N, M;
   int64_t K;
   cin >> N >> M >> K;
 
   vector<int> values(N);
   for (auto &value : values)
      cin >> value;
 
   vector<pair<int, int>> edges;
   for (int i = 0; i < M; ++i) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      edges.emplace_back (u, v);
   }
 
   int lo = 0, hi = 1e9 + 7, best = -1;
   while(lo <= hi) {
      int mid = (lo + hi) / 2;
 
      vector<vector<int>> adj(N);
      vector<int> good(N);
 
      for (int a = 0; a < N; ++a)
         if (values[a] <= mid) 
            good[a] = 1;
 
      for (auto [u, v] : edges)
         if (good[u] && good[v]) 
            adj[u].push_back(v);
 
      vector<int> top = topological_sort (adj);
      bool works = false;
 
      works |= top.size() < N;
 
      if (!works) {
         vector<int> dp(N);
         for (int a = 0; a < N; ++a)
            if (good[a])
               dp[a] = 1;
            
         vector<int> loc(N);
         for (int i = 0; i < N; ++i)
            loc[top[i]] = i;
 
         for (int i = 0; i < N; ++i) {
            int node = top[i];
            for (int neigh : adj[node]) {
               int in = loc[neigh];
               dp[in] = max (dp[in], dp[i] + 1);
            }
         }
 
         works |= *max_element(dp.begin(), dp.end()) >= K;
      }
 
      if (works) {
         best = mid;
         hi = mid - 1;
      }
 
      else {
         lo = mid + 1;
      }
   }
 
   cout << best << '\n';
}
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
 
   int tt = 1;
   // cin >> tt;
 
   while(tt--)
      test_case();
}