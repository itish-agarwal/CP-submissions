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
const int nax = 3e5 + 7;
int A[nax], B[nax], dp[nax][3];
vector<int> adj[nax];

int Dfs (int a, int par, int p) {
   int cur_color = p < 2 ? p : A[a];

   if (dp[a][p] > -1)
      return dp[a][p];

   if (cur_color != B[a]) {
      int r = 1;
      for (int b : adj[a])
         if (b != par)
            r += Dfs (b, a, B[a]);

      return dp[a][p] = r;
   }
   else {
      int r0 = 0, r1 = 1;
      for (int b : adj[a]) 
         if (b != par) {
            r0 += Dfs (b, a, p);
            r1 += Dfs (b, a, B[a]);
         }

      return dp[a][p] = min (r0, r1);
   }
}

void test_case() {
   int N;
   cin >> N;

   for (int i = 0; i < N; ++i)
      cin >> A[i];

   for (int i = 0; i < N; ++i)
      cin >> B[i];   

   for (int i = 0; i <= N; ++i) {
      adj[i].clear();
      dp[i][0] = dp[i][1] = dp[i][2] = -1;
   }

   for (int i = 0; i < N - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a, --b;
      adj[a].push_back(b);
      adj[b].push_back(a);
   }

   cout << Dfs (0, -1, 2) << '\n';
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int tests = 1;
   cin >> tests;

   while(tests--)
      test_case();
}