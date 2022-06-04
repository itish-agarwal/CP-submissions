#include <bits/stdc++.h>
 
using namespace std;
using namespace chrono;
 
#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << ": "; pr(x); cout << "]\n";
#else
#define debug(x...)
#endif
 
void pr(string x)  { cout << '\"' << x << '\"'; }
void pr(char x)  { cout << '\'' << x << '\''; }
void pr(long long x)  { cout << x; }
void pr(double x)  { cout << x; }
void pr(bool x)  { cout << x; }
void pr(int x)  { cout << x; }
 
template <class T, class V> void pr(const pair<T, V> &x);
template <class T, class V> void pr(const map<T, V>& mp);
template <class T, class... V> void pr(T t, V... v);
template <class T> void pr(const multiset<T>& pq);
template <class T> void pr(const vector<T>& v);
template <class T> void pr(const set<T>& pq);
 
template <class T, class V> void pr(const pair<T, V>& x) {
   cout << "{"; pr(x.first); cout << ", "; pr(x.second); cout << "}";
}
template <class T, class V> void pr(const map<T, V>& mp) {
   for (auto it = mp.begin(); it != mp.end(); ++it) { pr(*it); cout << " "; }
}
template <class T> void pr(const multiset<T>& pq) {
   vector<T> values(pq.begin(), pq.end()); pr(values);
}
template <class T> void pr(const vector<T>& v) {
   for (int i = 0; i < (int) v.size(); ++i) { pr(v[i]); cout << (i + 1 < (int) v.size() ? " " : ""); }
}
template <class T> void pr(const set<T>& pq) {
   vector<T> values(pq.begin(), pq.end()); pr(values);
}
template <class T, class... V> void pr(T t, V... v) {
   pr(t); if(sizeof...(v)) cout << " | "; pr(v...);
}
//Global space begins
 
const int nax = 5e5 + 7;
map<int, map<int, int>> S[nax];
vector<pair<int, int>> queries[nax];
int w[nax], result[nax], d[nax];
vector<int> adj[nax];
string code;
 
int merge (int a, int b) {
   if (S[w[a]].size() < S[w[b]].size()) 
      swap (a, b);
 
   int id = w[a];
   for (auto it = S[w[b]].begin(); it != S[w[b]].end(); ++it) {
      int ht = it -> first;
      for (auto pr : S[w[b]][ht]) {
         int alphabet = pr.first;
         int freq = pr.second;
         S[id][ht][alphabet] += freq;
      }
   }
 
   w[b] = id;
   return id;
}
 
void Dfs (int a, int pr) {
   int j = w[a];
   for (int b : adj[a])
      if (b != pr) {
         Dfs (b, a);
         j = merge (j, w[b]);
      }
 
   w[a] = j;
   for (auto [in, hh] : queries[a]) {
      int odd = 0;
      for (int k = 0; k < 26; ++k)
         if (S[j][hh].count (k) != 0)
            odd += S[j][hh][k] % 2;
 
      result[in] = odd < 2;
   }
}
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
 
   int N, Q;
   cin >> N >> Q;
   vector<int> P(N, -1);
   for (int i = 1; i < N; ++i) {
      cin >> P[i];
      --P[i];
      adj[i].push_back(P[i]);
      adj[P[i]].push_back(i);
   }
 
   cin >> code;
 
   for (int q = 0; q < Q; ++q) {
      int v, h;
      cin >> v >> h;
      --h, --v;
      queries[v].emplace_back (q, h);
   }
 
   function <void (int, int)> dfs = [&](int a, int pr) {
      for (int b : adj[a])
         if (b != pr) {
            d[b] = d[a] + 1;
            dfs (b, a);
         }
   };
 
   dfs (0, -1);
 
   for (int i = 0; i < N; ++i) {
      S[i][d[i]][code[i]-'a'] = 1;
      w[i] = i;
   }
 
   Dfs (0, -1);
 
   for (int i = 0; i < Q; ++i) 
      cout << (result[i] ? "Yes" : "No") << '\n';
}