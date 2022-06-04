#include <bits/stdc++.h>
 
using namespace std;
const int nax = 5e5 + 7;
 
struct DSURollback {
   // int p[nax], r[nax], compsz[nax];
   vector<int> p, r, compsz;
   vector<pair<int, int>> S;
   int n, cur = -1, comp;
 
   DSURollback (int _n) {
      n = _n;
      comp = n;
      p.resize (n);
      r.assign (n, 1);
      compsz.resize (nax);
      iota (p.begin(), p.end(), 0);
      // for (int x = 0; x < n; ++x)
         // p[x] = x, r[x] = 1;
   }
 
   int get (int x) {
      while (x ^ p[x]) x = p[x];
      return x;
   }
 
   void unite (int x, int y) {
      x = get (x);
      y = get (y);
      if (x ^ y) {
         if (r[y] > r[x]) swap (x, y);
         p[y] = x;
         r[x] += r[y];
         S.emplace_back (y, x);
 
         cur += 1;
         compsz[cur] = comp;
         comp -= 1;
      }
   }
 
   void rollback (int T) {
      while (cur > T) {
         int y = S[cur].first;
         int x = S[cur].second;
         p[y] = y;
         r[x] -= r[y];
         comp = compsz[cur];
         S.pop_back();
         cur -= 1;
      }
   }
};            
 
vector<vector<pair<int, int>>> edges;
DSURollback *curuf;
int64_t ans;
 
void Dfs (int l, int r) {
   if (l == r) {
      for (auto &pr : edges[l]) {
         int x = curuf -> get(pr.first);
         int y = curuf -> get(pr.second);
         ans += (int64_t) curuf -> r[x] * curuf -> r[y];
      }
 
      return;
   }
 
   int mid = (l + r) >> 1;
   int T = curuf -> cur;
 
   for (int i = mid + 1; i <= r; ++i)
      for (auto &pr : edges[i])
         curuf -> unite (pr.first, pr.second);
 
   Dfs (l, mid);
   curuf -> rollback (T);
 
   for (int i = l; i <= mid; ++i)
      for (auto &pr : edges[i])
         curuf -> unite (pr.first, pr.second);
 
   Dfs (mid + 1, r);
   curuf -> rollback (T);
}  
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
 
   int N;
   cin >> N;
   edges.resize (N);
   curuf = new DSURollback (N);
 
   for (int i = 0; i < N - 1; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      --a, --b, --c;
      edges[c].emplace_back (a, b);
   }
   Dfs (0, N - 1);
 
   cout << ans << '\n';
}