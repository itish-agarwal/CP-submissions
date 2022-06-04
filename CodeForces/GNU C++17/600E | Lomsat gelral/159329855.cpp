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
const int nax = 1e5 + 7;
map<int, int> S[nax];
int w[nax], mx[nax];
int64_t ans[nax], cnt[nax];
vector<int> adj[nax];
 
int merge (int a, int b) {
   if (S[w[a]].size() < S[w[b]].size()) 
      swap (a, b);
 
   int id = w[a];
   for (auto it = S[w[b]].begin(); it != S[w[b]].end(); ++it) {
      int c = it -> first;
      int f = it -> second;
      S[id][c] += f;
      if (S[id][c] > mx[id]) {
         mx[id] = S[id][c];
         cnt[id] = 0;
      }
 
      if (S[id][c] == mx[id])
         cnt[id] += c;
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
   ans[a] = cnt[j];
}
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int N;
   cin >> N;
 
   for (int i = 0; i < N; ++i) {
      int c;
      cin >> c;
      S[i][c] = 1;
      mx[i] = 1;
      w[i] = i;
      cnt[i] = c;
   }
 
   for (int i = 0; i < N - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a, --b;
      adj[a].push_back(b);
      adj[b].push_back(a);
   }
 
   Dfs (0, -1);
   for (int i = 0; i < N; ++i)
      cout << ans[i] << " ";
 
   cout << '\n';
}