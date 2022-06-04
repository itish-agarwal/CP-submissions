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
template <class T> 
ostream& operator << (ostream& stream, const vector<T>& values) {
   for (T v : values) 
      cout << v << " ";

   return stream;
}
template <class T>
void print_vector(const vector<T>& values, int from = -1, int to = -1) {
   if(from < 0) from = 0;
   if(to < 0) to = int(values.size()) - 1;

   for(int i = from; i <= to; ++i) 
      cout << values[i] << (i < to ? ' ' : '\n');
}

void ckmin (int64_t &a, int64_t b) {
   a = min (a, b);
}

const int64_t INF = (int64_t) 2e17 + 9;
const int nax = 1e5 + 7;
multiset<int64_t> S[nax];
vector<int> adj[nax];
int w[nax];

int merge (int a, int b, vector<int64_t> &result) {
   if (S[w[a]].size() < S[w[b]].size())
      swap (S[a], S[b]);

   int id = w[a];
   for (auto el : S[w[b]]) {
      auto it = S[id].lower_bound (el);
      if (it != S[id].end()) 
         ckmin (result[id], (*it ^ el));

      it = S[id].upper_bound (el);
      if (it != S[id].begin())
         ckmin (result[id], (*prev(it) ^ el));

      S[id].insert (el);
   }

   S[w[b]].clear();
   return w[b] = id;
}

void Dfs (int a, int pr, vector<int64_t> &result) {
   int j = w[a];
   for (int b : adj[a])
      if (b != pr) {
         Dfs (b, a, result);
         ckmin (result[a], result[b]);
         j = merge (j, w[b], result);
      }  

   w[a] = j;
}

void test_case() {
   int N;
   cin >> N;

   for (int i = 0; i <= N; ++i) {
      adj[i].clear();
      S[i].clear();
      w[i] = i;
   }

   for (int i = 0; i < N - 1; ++i) {
      int x, y;
      cin >> x >> y;
      --x, --y;
      adj[x].push_back (y);
      adj[y].push_back (x);
   }

   for (int i = 0; i < N; ++i) {
      int64_t a;
      cin >> a;
      S[i].insert (a);
   }

   vector<int64_t> result (N, INF);
   Dfs (0, -1, result);

   for (auto &r : result)
      if (r >= INF) r = -1;

   print_vector<int64_t> (result);
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int tests = 1;
   cin >> tests;

   while(tests--)
      test_case();
}